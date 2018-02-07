#ifndef NAMEGEN_H
#define NAMEGEN_H

#include "defs.h"

struct genRule
{
		QString ruleName;
		QStringList ruleData;
};

class ExternalRuleGen
{
	private:
		QList<genRule> ruleSet;
	public:
		ExternalRuleGen();
		ExternalRuleGen(QString ruleSetName);
		QString genByRule();
};

class NameGenRuleFactory
{
	private:
		static NameGenRuleFactory *instance;
		QMap< QString, ExternalRuleGen* > ruleGenSets;
		NameGenRuleFactory();
	public:
		static NameGenRuleFactory * getInstance();
		ExternalRuleGen *getRuleGenerator(QString ruleSetName);
};

// генератор имен
class INameGen
{
	public:
		INameGen();
		virtual QString randomActorName() = 0;
		virtual QString randomEffectName() = 0;
		virtual QString randomActionName() = 0;
		virtual QString randomTeamName() = 0;
		virtual QString randomUID() = 0;
		~INameGen();
};

class NameGen : public INameGen
{
	private:
		ExternalRuleGen *currentGenerator;
		NameGenRuleFactory *usedFactory;
	public:
		NameGen();
		QString randomActorName();
		QString randomEffectName();
		QString randomActionName();
		QString randomTeamName();
		QString randomUID();
		~NameGen();
};

#endif // NAMEGEN_H
