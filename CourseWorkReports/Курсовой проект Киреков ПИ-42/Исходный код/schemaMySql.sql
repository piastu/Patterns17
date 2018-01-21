CREATE TABLE `ClassifierInfo` (
	`ID` INT NOT NULL AUTO_INCREMENT,
	`Name` varchar(300) NOT NULL,
	`InputFormat` varchar(300) NOT NULL,
	`NumberOfClasses` INT NOT NULL,
	`Code` INT NOT NULL UNIQUE,
	`ClassifierFile` varchar(1000) NOT NULL,
	`IDClassifierType` INT NOT NULL,
	PRIMARY KEY (`ID`)
);

CREATE TABLE `ClassifierType` (
	`ID` INT NOT NULL AUTO_INCREMENT,
	`Name` varchar(300) NOT NULL,
	`Code` INT NOT NULL UNIQUE,
	PRIMARY KEY (`ID`)
);

CREATE TABLE `ClassifierAliases` (
	`ID` INT NOT NULL AUTO_INCREMENT,
	`Name` varchar(300) NOT NULL,
	`Index` INT NOT NULL,
	`IDClassifierInfo` INT NOT NULL,
	PRIMARY KEY (`ID`)
);

ALTER TABLE `ClassifierInfo` ADD CONSTRAINT `ClassifierInfo_fk0` FOREIGN KEY (`IDClassifierType`) REFERENCES `ClassifierType`(`ID`);

ALTER TABLE `ClassifierAliases` ADD CONSTRAINT `ClassifierAliases_fk0` FOREIGN KEY (`IDClassifierInfo`) REFERENCES `ClassifierInfo`(`ID`);

