#ifndef MODEL_H
#define MODEL_H

#include <QBitArray>
#include <QCoreApplication>
#include <QFile>
#include <QMessageBox>
#include <QObject>
#include <QPainter>
#include <QPair>
#include <QtConcurrent/QtConcurrent>
#include <QThread>
#include <QTime>
#include <dish.h>
#include <entity.h>
#include <person.h>
#include <util.h>
#include <cmath>
#include <iostream>

using namespace std;

#define color_grid QColor(80, 80, 80)
#define color_hover QColor(100, 0, 0)
#define color_entrance QColor(0, 64, 128)
#define point_fail QPoint(-1, -1)

// Класс схемы модели
// Используется только в одном экземпляре
class Model : public QObject
{
		Q_OBJECT
	public:
		static Model &getInstance();
		void setRoomSize(int width, int height);	// установить размер помещения
		void setPlacementID(int id);
		void setPlacementIDSub(int id);
		void setDesignMode(bool mode);	// режим дизайна
		void addCustomer(float pocketMoney);	// добавить посетителя
		void addCustomerGroup(float pocketMoney, int group);	// добавить группу посетителей
		void addDish(Dish *dish);
		Dish * getDish(int id);
		void deleteDish(int id);
		QList<QPoint> findPath(QPoint src, QPoint dest);	// найти путь от точки до точки
		QList<QPoint> findFreeNeighbors(QPoint src);	// поиск свободных соседей
		QPoint findEntryPoint(QPoint src, QPoint dest);	// поиск точки, к которой можно подойти
		int getTablesCount();		// получить количество столов
		bool getCellState(QPoint cell);	// получить состояние ячейки
		void setEmployeeCellsState(bool state);
		bool verifyPaths();
		void resetModel(bool fullReset);
		bool writeToStream(QDataStream &outp);
		bool readFromStream(QDataStream &inp);
		void putItems(int trays, int towels, int forks, int spoons, int knives);
		void activateEmployees();
	private:
		explicit Model(QObject *parent = 0);
		Model(Model const&, QObject *parent);
		Model& operator =(Model const&);
		~Model();
		QList<bool> freeCells;		// свободные клетки
		QPointF clickCoord;		// координата клетки
		QPair<int, int> roomSize;		// размер помещения
		QList<Dish *> dishesAvailable;		// меню
		QList<Entity *> entities;		// объекты карты
		QPoint entrance;		// точка входа
		QList<Person *> employees;		// персонал
		QList<Person *> customers;		// посетителм
		QList<Person *> customerQueue;	// очередь посетителей
		QList<QPoint> queuePath;		// путь очереди
		QList<QThread *> threadPool;		// простр-во потоков
		QList<int> countersShortcuts;		// ссылки на рабочие объекты
		bool isDesignMode;		// режим дизайна
		int placementID, placementIDSub;	// и его команды

	signals:
		void needsRepaint();
		void message(QString msg);

	public slots:
		void Draw(QPainter *pntr, QRectF geom);
		void clickAtCoord(QPointF pos, QRectF geom);
		void onRepaintRequest();
		void customerMovement();
		void employeeMovement();
		void pickDish();
		void pickFreeTable();
		void customerAction();
		void employeeAction();
		void deletePerson();
		void getMessage(QString msg);
};

#endif // MODEL_H
