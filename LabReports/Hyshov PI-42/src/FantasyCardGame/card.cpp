#include "card.h"

ICard::ICard(QObject *parent):QObject(parent)
{

}

template <typename T>
ICollection<T>::ICollection()
{

}

Collection::Collection()
{

}

Collection::Collection(QList<ICard *> _data):Collection()
{
	data = _data;
}

ICard * Collection::at(int id)
{
	return data[id];
}

void Collection::removeAt(int id)
{
	data.removeAt(id);
}

void Collection::replaceAt(int id, ICard *src)
{
	if (id < data.size())
		data[id] = src;
}

int Collection::count()
{
	return data.size();
}

Iterator *Collection::getIterator()
{
	return new Iterator(this);
}

template <typename T>
IIterator<T>::IIterator()
{

}

Iterator::Iterator()
{

}

Iterator::Iterator(ICollection<ICard *> *coll):Iterator()
{
	data = coll;
	currID = -1;
}

ICard * Iterator::getNext()
{
	return data->at(++currID);
}

void Iterator::removeCurrentElement()
{
	data->removeAt(currID);
}

bool Iterator::hasNext()
{
	return ((currID + 1) < data->count());
}

ActorCard::ActorCard(QObject *parent):ICard(parent)
{
	cio = NULL;
	NameGen *ng = new NameGen();
	bg = QColor(Random::randInt(0, 255),
				Random::randInt(0, 255),
				Random::randInt(0, 255));
	healthInit = health = 100;
	energyInit = energy = 100;
	selectedAction = -1;
	uid = ng->randomUID();
	delete ng;
}

void ActorCard::act(QList<ICard *> cardsToAffect)
{
	GameSession *gs = GameSession::getInstance();
	if (energy <= 0)
		return;
	QVector<StatsTransmitter *> transmitters;
	QMap< StatsTransmitter *, ICard * > transMapping;
	StatsTransmitter *srcTrans = new StatsTransmitter();
	for (int i = 0; i < cardsToAffect.size(); i++)
	{
		StatsTransmitter *st = new StatsTransmitter();
		connect(st, SIGNAL(sendStat(QString,int,bool)), cardsToAffect[i], SLOT(acceptStat(QString,int,bool)));
		transmitters.push_back(st);
		transMapping[st] = cardsToAffect[i];
	}
	connect(srcTrans, SIGNAL(sendStat(QString,int,bool)), this, SLOT(acceptStat(QString,int,bool)));
	int effectsNum = actionEffect.size();
	if (effectsNum == 1)
	{
		gs->msgRepeater(this->getName() + " использует " + actionEffect[0]->getName());
		actionEffect[0]->act(transmitters, srcTrans);
	}
	else
	{
		if (selectedAction != -1)
		{
			actionEffect[selectedAction]->act(transmitters, srcTrans);
			selectedAction = -1;
		}
		else
		{
			QList<IEffect *> pick = defaultSelector->selectEffect(actionEffect);

			for (int i = 0; i < pick.size(); i++)
			{
				gs->msgRepeater(this->getName() + " использует " + pick[i]->getName());
			}
			QVector<StatsTransmitter *> selectedTrans;
			for (int j = 0; j < transmitters.size(); j++)
			{
				if ((transMapping[transmitters[j]])->getStat("health") > 0)
				{
					gs->msgRepeater(this->getName() + " воздействует на " + transMapping[transmitters[j]]->getName());
					selectedTrans.push_back(transmitters[j]);
				}
			}
			EffectChainlink *efc = new EffectChainlink(pick.takeLast());
			while (!pick.empty())
				efc = new EffectChainlink(pick.takeLast(), efc);
			efc->act(selectedTrans, srcTrans);
			//pick[i]->act(selectedTrans, srcTrans);
			delete efc;
		}
	}
	while (!transmitters.empty())
		delete transmitters.takeAt(0);
	delete srcTrans;

}

QString ActorCard::getName()
{
	return name;
}

void ActorCard::setName(QString cardName)
{
	name = cardName;
}

QString ActorCard::getUID()
{
	return uid;
}

void ActorCard::setUID(QString id)
{
	uid = id;
}

QColor ActorCard::getBG()
{
	return bg;
}

void ActorCard::setBG(QColor bg)
{
	this->bg = bg;
}

int ActorCard::getStat(QString statName)
{
	if (statName == "health")
		return health;
	else if (statName == "energy")
		return energy;
	else if (statName == "healthInit")
		return healthInit;
	else if (statName == "energyInit")
		return energyInit;
	else if (statName == "actionNum")
		return actionEffect.size();
	else return -1;
}

void ActorCard::setStat(QString statName, int statVal, bool isInc)
{
	if (statName == "health")
	{
		if (isInc)
			health += statVal;
		else
			health = statVal;
	}
	else if (statName == "energy")
	{
		if (isInc)
			energy += statVal;
		else
			energy = statVal;
	}
	else if (statName == "healthInit")
	{
		if (isInc)
			healthInit += statVal;
		else
			healthInit = statVal;
	}
	else if (statName == "energyInit")
	{
		if (isInc)
			energyInit += statVal;
		else
			energyInit = statVal;
	}
	else if (statName == "selectedAction")
		selectedAction = statVal;
	updateStats();
}

void ActorCard::setEffects(QList<IEffect *> effects)
{
	actionEffect = effects;
}

QList<IEffect *> ActorCard::getEffects()
{
	return actionEffect;
}

void ActorCard::setEffectSelector(IEffectSelector *selector)
{
	defaultSelector = selector;
}

IEffectSelector *ActorCard::getEffectSelector()
{
	return defaultSelector;
}

void ActorCard::updateStats()
{
	if (health <= 0)
	{
		disposeMe();
		if (cio)
			cio->dispose(this);
	}
	else
	{
		if (cio)
			cio->notify(listItem(this->getDrawable(), this->getPseudoDrawable(), this->name, this->uid));
	}
}

QImage ActorCard::getDrawable(int height)
{
	QImage img = QImage(height * 0.75, height, QImage::Format_RGBA8888);
	QPainter pntr(&img);
	// тут, по идее должна быть какая-нибудь текстурка с каким-либо героем
	pntr.fillRect(0, 0, height * 0.75, height, QBrush(bg));
	pntr.fillRect(height * 0.05 * 0.75, height * 0.05, height * 0.9 * 0.75, height * 0.5, QBrush(Qt::white));
	// окошко с состоянием
	pntr.fillRect(height * 0.05 * 0.75, height * 0.6, height * 0.9 * 0.75, height * 0.35, QBrush(Qt::white));
	QFont f = pntr.font();
	f.setPixelSize(height * 0.1);
	pntr.setFont(f);
	pntr.drawText(height * 0.75 * 0.1, height * 0.7, "HP: " + QString::number(health));
	pntr.drawText(height * 0.75 * 0.1, height * 0.85, "MP: " + QString::number(energy));
	pntr.end();
	return img;
}

QString ActorCard::getPseudoDrawable()
{
	return "A(HP:" + QString::number(health) + ";MP:" + QString::number(energy) + ")";
}

QString ActorCard::getFullInfo()
{
	QString result = "";
	result = name + "\nСпособности:";
	for (int i = 0; i < actionEffect.size(); i++)
		result += "\n" + actionEffect[i]->getFullInfo();
	return result;
}

QList<effectInfoItem> ActorCard::getEffectsInfo()
{
	QList<effectInfoItem> result;
	for (int i = 0; i < actionEffect.size(); i++)
	{
		result.push_back(actionEffect[i]->getInfo());
	}
	return result;
}

void ActorCard::reset()
{
	health = healthInit;
	energy = energyInit;
	selectedAction = -1;
}

void ActorCard::attachObserver(CardInfoObserver *observer)
{
	cio = observer;
}

void ActorCard::detachObserver(CardInfoObserver *observer)
{
	if (cio == observer)
		cio = NULL;
}

void ActorCard::loadFromStream(QDataStream *stream)
{
	*stream >> uid;
	*stream >> name;
	*stream >> bg;
	*stream >> healthInit;
	*stream >> energyInit;
	*stream >> health;
	*stream >> energy;
	int effCount = 0;
	*stream >> effCount;
	QList<IEffect *> effs;
	for (int i = 0; i < effCount; i++)
	{
		int effType;
		*stream >> effType;
		IEffect *eff;
		switch (effType)
		{
			case 'A':
				eff = new AttackEffect();
				break;
			case 'H':
				eff = new HelpEffect();
				break;
			case 'D':
				eff = new EffectDestabilizer();
				break;
		}
		eff->loadFromStream(stream);
		effs.push_back(eff);
	}
	while (!actionEffect.empty())
		delete actionEffect.takeFirst();
	actionEffect = effs;
	int selectorType = 0;
	*stream >> selectorType;
	switch (selectorType)
	{
		case 0:
			defaultSelector = new EffectSelectorAll();
			break;
		case 1:
			defaultSelector = new EffectSelectorRandom();
			break;
		default:
			break;
	}
}

void ActorCard::saveToStream(QDataStream *stream)
{
	int sizeInt = 0;
	*stream << 'A';
	*stream << uid;
	*stream << name;
	*stream << bg;
	*stream << healthInit;
	*stream << energyInit;
	*stream << health;
	*stream << energy;
	sizeInt = actionEffect.size();
	*stream << sizeInt;
	for (int i = 0; i < sizeInt; i++)
	{
		actionEffect[i]->saveToStream(stream);
	}
	*stream << defaultSelector->getType();
}

void ActorCard::acceptVisitor(CardVisitor *visitor)
{
	visitor->visitActorCard(this);
}

void ActorCard::makeActionSelection(int id)
{
	selectedAction = id;
}

void ActorCard::acceptStat(QString statName, int statVal, bool isInc)
{
	this->setStat(statName, statVal, isInc);
}

ActionCard::ActionCard(QObject *parent):ICard(parent)
{
	cio = NULL;
	NameGen *ng = new NameGen();
	bg = QColor(Random::randInt(0, 255),
				Random::randInt(0, 255),
				Random::randInt(0, 255));
	uid = ng->randomUID();
	delete ng;
}

void ActionCard::act(QList<ICard *> cardsToAffect)
{
	GameSession *gs = GameSession::getInstance();
	QVector<StatsTransmitter *> transmitters;
	StatsTransmitter *srcTrans = new StatsTransmitter();
	gs->msgRepeater(this->getName() + " использует " + actionEffect->getName());
	for (int i = 0; i < cardsToAffect.size(); i++)
	{
		gs->msgRepeater(this->getName() + " воздействует на " + cardsToAffect[i]->getName());
		StatsTransmitter *st = new StatsTransmitter();
		connect(st, SIGNAL(sendStat(QString,int,bool)), cardsToAffect[i], SLOT(acceptStat(QString,int,bool)));
		transmitters.push_back(st);
	}
	connect(srcTrans, SIGNAL(sendStat(QString,int,bool)), this, SLOT(acceptStat(QString,int,bool)));
	actionEffect->act(transmitters, srcTrans);
	while (!transmitters.empty())
		delete transmitters.takeAt(0);
	delete srcTrans;
	disposeMe();
	if (cio != NULL)
		cio->dispose(this);
}

QString ActionCard::getName()
{
	return name;
}

void ActionCard::setName(QString cardName)
{
	name = cardName;
}

QString ActionCard::getUID()
{
	return uid;
}

void ActionCard::setUID(QString id)
{
	uid = id;
}

QColor ActionCard::getBG()
{
	return bg;
}

void ActionCard::setBG(QColor bg)
{
	this->bg = bg;
}

int ActionCard::getStat(QString statName)
{
	if (statName == "actionNum")
		return 1;
	else if (statName == "health" || statName == "energy")
		return 999;
	return 0;
}

void ActionCard::setStat(QString statName, int statVal, bool isInc)
{
	return;
}

void ActionCard::setEffects(QList<IEffect *> effects)
{
	actionEffect = effects[0];
}

QList<IEffect *> ActionCard::getEffects()
{
	return {actionEffect};
}

void ActionCard::updateStats()
{

}

QImage ActionCard::getDrawable(int height)
{
	QImage img = QImage(height * 0.75, height, QImage::Format_RGBA8888);
	QPainter pntr(&img);
	pntr.fillRect(0, 0, height * 0.75, height, QBrush(bg));
	pntr.fillRect(height * 0.05 * 0.75, height * 0.05, height * 0.9 * 0.75, height * 0.5, QBrush(Qt::white));
	pntr.end();
	return img;
}

QString ActionCard::getPseudoDrawable()
{
	return "E";
}

QString ActionCard::getFullInfo()
{
	QString result = "";
	result = name + "\nСпособности:";
	result += "\n" + actionEffect->getFullInfo();
	return result;
}

QList<effectInfoItem> ActionCard::getEffectsInfo()
{
	return {actionEffect->getInfo()};
}

void ActionCard::reset()
{

}

void ActionCard::attachObserver(CardInfoObserver *observer)
{
	cio = observer;
}

void ActionCard::detachObserver(CardInfoObserver *observer)
{
	if (cio == observer)
		cio = NULL;
}

void ActionCard::loadFromStream(QDataStream *stream)
{
	*stream >> uid;
	*stream >> name;
	*stream >> bg;
	IEffect *eff;
	int effType;
	*stream >> effType;
	switch (effType)
	{
		case 'A':
			eff = new AttackEffect();
			break;
		case 'H':
			eff = new HelpEffect();
			break;
		case 'D':
			eff = new EffectDestabilizer();
			break;
	}
	eff->loadFromStream(stream);
	actionEffect = eff;
}

void ActionCard::saveToStream(QDataStream *stream)
{
	*stream << 'E';
	*stream << uid;
	*stream << name;
	*stream << bg;
	actionEffect->saveToStream(stream);
}

void ActionCard::acceptVisitor(CardVisitor *visitor)
{
	visitor->visitActionCard(this);
}

void ActionCard::makeActionSelection(int id)
{
	return;
}

void ActionCard::acceptStat(QString statName, int statVal, bool isInc)
{
	this->setStat(statName, statVal, isInc);
}

TeamCard::TeamCard(QObject *parent):ICard(parent)
{
	cio = NULL;
	NameGen *ng = new NameGen();
	bg = QColor(Random::randInt(0, 255),
				Random::randInt(0, 255),
				Random::randInt(0, 255));
	uid = ng->randomUID();
	delete ng;
}

void TeamCard::act(QList<ICard *> cardsToAffect)
{
	GameSession *gs = GameSession::getInstance();
	if (this->getStat("energy") == 0)
		return;
	ICard *member;
	do
	{
		member = members[Random::randInt(0, members.size() - 1)];
	} while (member->getStat("energy") <= 0);
	gs->msgRepeater(this->getName() + " выводит " + member->getName());
	member->act(cardsToAffect);
	updateStats();
}

QString TeamCard::getName()
{
	return name;
}

void TeamCard::setName(QString cardName)
{
	name = cardName;
}

QString TeamCard::getUID()
{
	return uid;
}

void TeamCard::setUID(QString id)
{
	uid = id;
}

QColor TeamCard::getBG()
{
	return bg;
}

void TeamCard::setBG(QColor bg)
{
	this->bg = bg;
}

int TeamCard::getStat(QString statName)
{
	int result = 0;
	Collection *col = new Collection(members);
	Iterator *i = new Iterator(col);
	while (i->hasNext())
	{
		result += i->getNext()->getStat(statName);
	}
	return result;
}

void TeamCard::setStat(QString statName, int statVal, bool isInc)
{
	members[Random::randInt(0, members.size() - 1)]->setStat(statName, statVal, isInc);
	updateStats();
}

void TeamCard::setEffects(QList<IEffect *> effects)
{
	return;
}

QList<IEffect *> TeamCard::getEffects()
{
	return QList<IEffect *>();
}

void TeamCard::updateStats()
{
	if (this->getStat("health") <= 0)
	{
		disposeMe();
		if (cio)
			cio->dispose(this);
	}
	else
	{
		if (cio)
			cio->notify(listItem(this->getDrawable(), this->getPseudoDrawable(), this->name, this->uid));
	}
}

QImage TeamCard::getDrawable(int height)
{
	QList<QImage> memberDrawables;
	QImage img = QImage(height * 0.75, height, QImage::Format_RGBA8888);
	QPainter pntr(&img);
	pntr.fillRect(0, 0, height * 0.75, height, QBrush(bg));
	pntr.fillRect(height * 0.05 * 0.75, height * 0.05, height * 0.9 * 0.75, height * 0.5, QBrush(Qt::white));
	Collection *col = new Collection(members);
	Iterator *it = new Iterator(col);
	int health = 0, energy = 0;
	while (it->hasNext())
	{
		ICard *member;
		member = it->getNext();
		memberDrawables.push_back(member->getDrawable(height * 0.5 * 0.75));
		health += member->getStat("health");
		energy += member->getStat("energy");
	}
	double xOffset = (height * 0.5 * 0.75) / (double)(memberDrawables.size());
	for (int i = 0; i < memberDrawables.size(); i++)
	{
		pntr.drawImage(height * 0.1 * 0.75 + xOffset * i, height * 0.1, memberDrawables[i]);
	}
	pntr.fillRect(height * 0.05 * 0.75, height * 0.6, height * 0.9 * 0.75, height * 0.35, QBrush(Qt::white));
	QFont f = pntr.font();
	f.setPixelSize(height * 0.1);
	pntr.setFont(f);
	pntr.drawText(height * 0.75 * 0.1, height * 0.7, "HP: " + QString::number(health));
	pntr.drawText(height * 0.75 * 0.1, height * 0.85, "MP: " + QString::number(energy));
	pntr.end();
	return img;
}

QString TeamCard::getPseudoDrawable()
{
	QString result = "@{";
	Collection *col = new Collection(members);
	Iterator *it = new Iterator(col);
	int health = 0, energy = 0;
	while (it->hasNext())
	{
		ICard *member;
		member = it->getNext();
		result += member->getPseudoDrawable();
		result += ";";
		health += member->getStat("health");
		energy += member->getStat("energy");
	}
	result += "}(HP:" + QString::number(health) + ";MP:" + QString::number(energy) + ")";
	return result;
}

QString TeamCard::getFullInfo()
{
	QString result;
	result = name;
	result += ":\n";
	Collection *col = new Collection(members);
	Iterator *it = col->getIterator();
	while (it->hasNext()) {
		result += "{";
		result += it->getNext()->getFullInfo();
		result += "}\n";
	}
	return result;
}

QList<effectInfoItem> TeamCard::getEffectsInfo()
{
	effectInfoItem result;
	result.canAffectEnemy = true;
	result.canAffectPlayer = true;
	result.effectType = 0;
	result.info = "(смешанный)";
	return {result};
}

void TeamCard::setMembers(QList<ICard *> _members, bool beaten)
{
	if (!beaten)
	{
		members = _members;
		int sizeInt = members.size();
		for (int i = 0; i < sizeInt; i++)
			connect(members[i], SIGNAL(disposeMe()), this, SLOT(cardDispose()));
	}
	else
	{
		membersBeaten = _members;
	}
}

QList<ICard *> TeamCard::getMembers(bool beaten)
{
	return (beaten ? membersBeaten : members);
}

void TeamCard::reset()
{
	while (!membersBeaten.empty())
	{
		ICard *member = membersBeaten.takeAt(0);
		member->reset();
		members.push_back(member);
	}
}

void TeamCard::attachObserver(CardInfoObserver *observer)
{
	cio = observer;
}

void TeamCard::detachObserver(CardInfoObserver *observer)
{
	if (cio == observer)
		cio = NULL;
}

void TeamCard::loadFromStream(QDataStream *stream)
{
	int sizeInt = 0;
	*stream >> uid;
	*stream >> name;
	*stream >> bg;
	QList<ICard *> storedMembers, storedMembersBeaten;
	*stream >> sizeInt;
	for (int i = 0; i < sizeInt; i++)
	{
		ICard *card;
		int cardType;
		*stream >> cardType;
		switch (cardType)
		{
			case 'A':
				card = new ActorCard();
				break;
			case 'E':
				card = new ActionCard();
				break;
			case 'T':
				card = new TeamCard();
				break;
		}
		card->loadFromStream(stream);
		connect(card, SIGNAL(disposeMe()), this, SLOT(cardDispose()));
		storedMembers.push_back(card);
	}
	*stream >> sizeInt;
	for (int i = 0; i < sizeInt; i++)
	{
		ICard *card;
		int cardType;
		*stream >> cardType;
		switch (cardType)
		{
			case 'A':
				card = new ActorCard();
				break;
			case 'E':
				card = new ActionCard();
				break;
			case 'T':
				card = new TeamCard();
				break;
		}
		card->loadFromStream(stream);
		connect(card, SIGNAL(disposeMe()), this, SLOT(cardDispose()));
		storedMembersBeaten.push_back(card);
	}
	while (!members.empty())
		delete members.takeFirst();
	while (!membersBeaten.empty())
		delete membersBeaten.takeFirst();
	members = storedMembers;
	membersBeaten = storedMembersBeaten;
}

void TeamCard::saveToStream(QDataStream *stream)
{
	int sizeInt = 0;
	*stream << 'T';
	*stream << uid;
	*stream << name;
	*stream << bg;
	sizeInt = members.size();
	*stream << sizeInt;
	for (int i = 0; i < sizeInt; i++)
		members[i]->saveToStream(stream);
	sizeInt = membersBeaten.size();
	*stream << sizeInt;
	for (int i = 0; i < sizeInt; i++)
		membersBeaten[i]->saveToStream(stream);
}

void TeamCard::acceptVisitor(CardVisitor *visitor)
{
	visitor->visitTeamCard(this);
}

void TeamCard::makeActionSelection(int id)
{
	return;
}

void TeamCard::acceptStat(QString statName, int statVal, bool isInc)
{
	this->setStat(statName, statVal, isInc);
}

void TeamCard::cardDispose()
{
	QObject *o = QObject::sender();
	ICard *card = (ICard *)o;
	int cardID = members.indexOf(card);
	if (cardID != -1)
	{
		membersBeaten.push_back(members.takeAt(cardID));
	}
	updateStats();
}

CardInfoObserver::CardInfoObserver(QObject *parent) : QObject(parent)
{

}

void CardInfoObserver::notify(listItem litem)
{
	GameSession::getInstance()->listItemUpdateRepeater(litem);
}

void CardInfoObserver::dispose(ICard *me)
{
	GameSession::getInstance()->disposeCard(me);
}

listItem getCardListItem(ICard *card)
{
	return listItem(card->getDrawable(), card->getPseudoDrawable(), card->getName(), card->getUID());
}

CardStreamWriter::CardStreamWriter() : CardVisitor()
{

}

void CardStreamWriter::setupStream(QDataStream *stream)
{
	this->stream = stream;
}

void CardStreamWriter::writeCard(ICard *card)
{
	card->acceptVisitor(this);
}

void CardStreamWriter::visitActorCard(ActorCard *card)
{
	int sizeInt = 0;
	*stream << 'A';
	*stream << card->getUID();
	*stream << card->getName();
	*stream << card->getBG();
	*stream << card->getStat("healthInit");
	*stream << card->getStat("energyInit");
	*stream << card->getStat("health");
	*stream << card->getStat("energy");
	QList<IEffect *> effs = card->getEffects();
	sizeInt = effs.size();
	*stream << sizeInt;
	for (int i = 0; i < sizeInt; i++)
	{
		effs[i]->saveToStream(stream);
	}
	*stream << card->getEffectSelector()->getType();
}

void CardStreamWriter::visitActionCard(ActionCard *card)
{
	*stream << 'E';
	*stream << card->getUID();
	*stream << card->getName();
	*stream << card->getBG();
	card->getEffects().at(0)->saveToStream(stream);
}

void CardStreamWriter::visitTeamCard(TeamCard *card)
{
	int sizeInt = 0;
	*stream << 'T';
	*stream << card->getUID();
	*stream << card->getName();
	*stream << card->getBG();
	QList<ICard *> members = card->getMembers(), membersBeaten = card->getMembers(true);
	sizeInt = members.size();
	*stream << sizeInt;
	while (!members.empty())
		writeCard(members.takeFirst());
	sizeInt = membersBeaten.size();
	*stream << sizeInt;
	while (!membersBeaten.empty())
		writeCard(membersBeaten.takeFirst());
}

ICard *matchCardPointer(char cardType)
{
	ICard *card;
	switch (cardType)
	{
		case 'A':
			card = new ActorCard();
			break;
		case 'E':
			card = new ActionCard();
			break;
		case 'T':
			card = new TeamCard();
			break;
		default:
			card = nullptr;
			break;
	}
	return card;
}

CardVisitor::CardVisitor()
{

}

CardStreamReader::CardStreamReader() : CardVisitor()
{

}

void CardStreamReader::setupStream(QDataStream *stream)
{
	this->stream = stream;
}

void CardStreamReader::readCard(ICard *card)
{
	card->acceptVisitor(this);
}

void CardStreamReader::visitActorCard(ActorCard *card)
{
	int bufInt;
	QString bufString;
	QColor bufCol;
	*stream >> bufString;
	card->setUID(bufString);
	*stream >> bufString;
	card->setName(bufString);
	*stream >> bufCol;
	card->setBG(bufCol);
	*stream >> bufInt;
	card->setStat("healthInit", bufInt);
	*stream >> bufInt;
	card->setStat("energyInit", bufInt);
	*stream >> bufInt;
	card->setStat("health", bufInt);
	*stream >> bufInt;
	card->setStat("energy", bufInt);
	int effCount = 0;
	*stream >> effCount;
	QList<IEffect *> effs;
	for (int i = 0; i < effCount; i++)
	{
		int effType;
		*stream >> effType;
		IEffect *eff;
		switch (effType)
		{
			case 'A':
				eff = new AttackEffect();
				break;
			case 'H':
				eff = new HelpEffect();
				break;
			case 'D':
				eff = new EffectDestabilizer();
				break;
		}
		eff->loadFromStream(stream);
		effs.push_back(eff);
	}
	card->setEffects(effs);
	IEffectSelector *effSel = nullptr;
	int selectorType = 0;
	*stream >> selectorType;
	switch (selectorType)
	{
		case 0:
			effSel = new EffectSelectorAll();
			break;
		case 1:
			effSel = new EffectSelectorRandom();
			break;
		default:
			break;
	}
	card->setEffectSelector(effSel);
}

void CardStreamReader::visitActionCard(ActionCard *card)
{
	QString bufString;
	QColor bufCol;
	*stream >> bufString;
	card->setUID(bufString);
	*stream >> bufString;
	card->setName(bufString);
	*stream >> bufCol;
	card->setBG(bufCol);
	IEffect *eff;
	int effType;
	*stream >> effType;
	switch (effType)
	{
		case 'A':
			eff = new AttackEffect();
			break;
		case 'H':
			eff = new HelpEffect();
			break;
		case 'D':
			eff = new EffectDestabilizer();
			break;
	}
	eff->loadFromStream(stream);
	card->setEffects({eff});
}

void CardStreamReader::visitTeamCard(TeamCard *card)
{
	int sizeInt = 0;
	QString bufString;
	QColor bufCol;
	*stream >> bufString;
	card->setUID(bufString);
	*stream >> bufString;
	card->setName(bufString);
	*stream >> bufCol;
	card->setBG(bufCol);
	QList<ICard *> storedMembers, storedMembersBeaten;
	*stream >> sizeInt;
	for (int i = 0; i < sizeInt; i++)
	{
		int cardType;
		*stream >> cardType;
		ICard *member = matchCardPointer(cardType);
		readCard(member);
		storedMembers.push_back(member);
	}
	*stream >> sizeInt;
	for (int i = 0; i < sizeInt; i++)
	{
		int cardType;
		*stream >> cardType;
		ICard *member = matchCardPointer(cardType);
		readCard(member);
		QObject::connect(member, SIGNAL(disposeMe()), card, SLOT(cardDispose()));
		storedMembersBeaten.push_back(member);
	}
	card->setMembers(storedMembers);
	card->setMembers(storedMembersBeaten, true);
}
