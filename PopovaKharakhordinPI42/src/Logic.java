package p2016;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;

abstract public class Logic {
	// на сколько изменяется шанс чего-либо каждую итерацию
	final static double gettingHungry = 0.0000005;	// голодает
	final static double gettingThursty = 0.0000006;	// хочет пить
	
	// на сколько изменяется шанс появления одного события после другого
	// TODO: больше вероятностей для всех событий
	final static double wannaLeave = 0.05;		// увеличение шанса того, что человек захочет уйти домой после события
	
	// вероятности появления работников
	// TODO: больше вероятностей для всех работ
	final static double goingToTheWork = 0.7;
	
	// вероятности событий, связанных с используемыми объектами
	final static double gonnaLeave = 0.001;				// человек уйдет

	final static double hasCloth = 0.5;					// у человека куртка
	final static double hasToPrint = 0.5;				// вероятность, что нужно будет распечатать
	final static double gonnaToCoatRoom = 0.3;			// он пойдет ее сдавать

	final static double wannaEat = 0.3;					// человек хочет есть
	final static double wannaDrink = 0.2;				// человек хочет пить
	
	final static int minPaperLimit = 10;				// предельный остаток бумаги в копицентре

	// вероятности при создании людей
	final static int minCash = 0, maxCash = 50;			// мин. и макс. налички
	final static int minCredit = 0, maxCredit = 200;	// мин. и макс. денег на карте
	final static int minPages = 1, maxPages = 10;		// мин. и макс. листов для распечатки
	
	// описание событий
	final static String goingToVending = "идет к кофейному автомату";
	final static String goingToPrint = "идет печатать";
	final static String goingToCoat = "идет в гардероб";
	final static String goingToCoatN = " (сдавать куртку)";
	final static String goingToCoatY = " (забирать куртку)";
	final static String goingToPost = "идет к посту";
	final static String goingToStore = "идет в магазин";
	final static String goingToATM = "идет к банкомату";
	final static String goingToExit = "идет на выход";
	final static String goingToDrink = " (пить)";
	final static String goingToEat = " (есть)";
	final static String goingToWalk = "гуляет";
	final static String nowWannaEat = "захотел есть";
	final static String nowWannaDrink = "захотел пить";
	final static String drankSome = "попил";
	final static String ateSome = "поел";
	final static String printed = "распечатал";
	final static String gaveCloth = "сдал куртку";
	final static String tookCloth = "взял куртку";
	final static String noCash = "не хватает налички, идет к банкомату";
	final static String noCredit = "денег нет, идет на выход";
	final static String goingBack = "возвращается с деньгами назад";
	final static String noDrinks = "нет ничего попить, идет на выход";
	final static String noMeals = "в магазине ничего нет, идет на выход";
	final static String noPaper = "нет бумаги для печати, идет на выход";
	final static String refillVending = "пришел пополнить автомат";
	final static String refillStore = "пришел пополнить товар в магазине";
	final static String refillCopy = "пришел пополнить бумагу";
	
	// генерация информации о человеке
	static void GeneratePersonInfo(Person p) {
		Random r = new Random();
		// наличные и кредитные деньги
		p.cash = r.nextInt(maxCash - minCash) + minCash;
		p.credit = r.nextInt(maxCredit - minCredit) + minCredit;
		// есть ли одежда
		if (r.nextDouble() < hasCloth)
			p.hasCloth = true;
		// хочет ли пить
		if (r.nextDouble() < wannaDrink)
			p.wantsToDrink = true;
		// хочет ли есть
		if (r.nextDouble() < wannaEat)
			p.wantsToEat = true;
		// нужно ли распечатать
		if (r.nextDouble() < hasToPrint)
			p.toPrint = r.nextInt(maxPages - minPages) + minPages;
		p.wannaDrinkProb = gettingThursty;
		p.wannaEatProb = gettingHungry;
		p.wannaLeave = gonnaLeave;
	}
	
	// куда пойдет человек
	static WayPoint WhereToGo(Person p, boolean justSpawned) {
		Random r = new Random();
		ArrayList<WayPoint> wps = Panel.getCurrentSimScreen()._waypoints;
		// перемешивание точек
		Collections.shuffle(wps);
		int action;	// куда пойдет человек
		// 0..5 - по типам объектов
		// -1 - гулять
		// -2 - на выход

		while (true) {
			// если человек только что появился
			if (justSpawned) {
				if (p.hasCloth)
					// пойдет ли сдавать куртку
					if (r.nextDouble() < gonnaToCoatRoom) {
							p.log.add(Logic.goingToCoat + Logic.goingToCoatN);
							action = 2;
							break;
						}
			}
			// человек уйдет
			if (r.nextDouble() < p.wannaLeave) {
				// есть куртка в гардеробе
				if (p.coatRoomCheck) {
						p.log.add(Logic.goingToCoat + Logic.goingToCoatY);
						action = 2;
						break;
					}
				// одежды нет
				if (!p.coatRoomCheck) {
					p.log.add(Logic.goingToExit);
					action = -2;
					break;
				}
			}
			// хочет есть
			if (p.wantsToEat) {
					p.log.add(Logic.goingToStore + Logic.goingToEat);
					action = 4;
					break;
				}
			// хочет пить
			if (p.wantsToDrink) {
				// где попить
				boolean goingToStore = r.nextBoolean();
				if (goingToStore) {
					p.log.add(Logic.goingToStore + Logic.goingToDrink);
					action = 4;
					break;
				} else {
					p.log.add(Logic.goingToVending + Logic.goingToDrink);
					action = 0;
					break;
				}
			}
			// нужно распечатать
			if (p.toPrint > 0) {
					p.log.add(Logic.goingToPrint);
					action = 1;
					break;
				}
			
			p.log.add(Logic.goingToWalk);
			action = -1;
			break;
		}
		if (!wps.isEmpty())
			for (WayPoint wp : wps) {
				if (action >= 0 && wp.getClass().getSimpleName().equals("UsableWayPoint")) {
					UsableWayPoint uwp = (UsableWayPoint) wp;
					if (uwp.object.getType() == action)
						return wp;
				}
				if (action < 0 && !wp.getClass().getSimpleName().equals("UsableWayPoint")) {
					switch (action) {
					case -1:
						if (!wp.isSpawn)
							return wp;
						break;
					case -2:
						if (wp.isSpawn)
							return wp;
						break;
					}
				}
			}
		// просто идет гулять
		for (WayPoint wp : wps)
			if (!wp.getClass().getSimpleName().equals("UsableWayPoint")) {
				p.log.add(Logic.goingToWalk);
				return wp;
			}
		System.out.println("null");
		return null;
	}
	// выбрать и найти дальнейший путь
	static boolean FindRandomPathToAnywhere(Person person, WayPoint start, boolean justSpawned) {
		WayPoint end_point = Logic.WhereToGo(person, justSpawned);

		// выбираем случайный путь через обход в глубину
		// TODO: самый короткий путь?
		App.dfs(start, end_point, new boolean[Panel.getCurrentSimScreen()._waypoints.size()], new ArrayList<WayPoint>(), person);
		if (person.path == null) {
			Panel.getCurrentSimScreen()._persons.remove(person);
			return false;
		}
		person.goingTo = person.path.get(0);
		person.path.remove(0);
		return true;
	}
	
	// найти путь до определенного используемого объекта
	static boolean FindRandomPathToUsable(Person person, WayPoint start, int type) {
		WayPoint end_point = null;
		for ( WayPoint wp : Panel.getCurrentSimScreen()._waypoints )
			if (wp.getClass().getSimpleName().equals("UsableWayPoint")) {
				UsableWayPoint uwp = (UsableWayPoint) wp;
				if (uwp.getObject().getType() == type) {
					end_point = wp;
					break;
				}
			}

		// выбираем случайный путь через обход в глубину
		// TODO: самый короткий путь?
		App.dfs(start, end_point, new boolean[Panel.getCurrentSimScreen()._waypoints.size()], new ArrayList<WayPoint>(), person);
		if (person.path == null) {
			Panel.getCurrentSimScreen()._persons.remove(person);
			return false;
		}
		person.goingTo = person.path.get(0);
		person.path.remove(0);
		return true;
	}

	// найти путь до выхода
	static boolean FindRandomPathToExit(Person person, WayPoint start) {
		WayPoint end_point = null;
		for ( WayPoint wp : Panel.getCurrentSimScreen()._waypoints )
			if (!wp.getClass().getSimpleName().equals("UsableWayPoint"))
				if (wp.isSpawn) {
					end_point = wp;
					break;
				}

		// выбираем случайный путь через обход в глубину
		// TODO: самый короткий путь?
		App.dfs(start, end_point, new boolean[Panel.getCurrentSimScreen()._waypoints.size()], new ArrayList<WayPoint>(), person);
		if (person.path == null) {
			Panel.getCurrentSimScreen()._persons.remove(person);
			return false;
		}
		person.goingTo = person.path.get(0);
		person.path.remove(0);
		return true;
	}
	// найти путь до заданной точки
	static boolean FindRandomPathToPoint(Person person, WayPoint start, WayPoint end) {
		// выбираем случайный путь через обход в глубину
		// TODO: самый короткий путь?
		App.dfs(start, end, new boolean[Panel.getCurrentSimScreen()._waypoints.size()], new ArrayList<WayPoint>(), person);
		if (person.path == null) {
			Panel.getCurrentSimScreen()._persons.remove(person);
			return false;
		}
		person.goingTo = person.path.get(0);
		person.path.remove(0);
		return true;
	}
}
