-- Создание базы данных
CREATE DATABASE Друзья_человека;

-- Использование базы данных
USE Друзья_человека;

-- Создание таблиц
CREATE TABLE Домашние_животные (
    id INT AUTO_INCREMENT PRIMARY KEY,
    тип_животного VARCHAR(50),
    имя VARCHAR(50),
    команда VARCHAR(100),
    дата_рождения DATE
);

CREATE TABLE Собаки (
    id INT PRIMARY KEY,
    FOREIGN KEY (id) REFERENCES Домашние_животные(id) ON DELETE CASCADE
);

CREATE TABLE Кошки (
    id INT PRIMARY KEY,
    FOREIGN KEY (id) REFERENCES Домашние_животные(id) ON DELETE CASCADE
);

CREATE TABLE Хомяки (
    id INT PRIMARY KEY,
    FOREIGN KEY (id) REFERENCES Домашние_животные(id) ON DELETE CASCADE
);

CREATE TABLE Вьючные_животные (
    id INT AUTO_INCREMENT PRIMARY KEY,
    тип_животного VARCHAR(50),
    имя VARCHAR(50),
    команда VARCHAR(100),
    дата_рождения DATE
);

CREATE TABLE Лошади (
    id INT PRIMARY KEY,
    FOREIGN KEY (id) REFERENCES Вьючные_животные(id) ON DELETE CASCADE
);

CREATE TABLE Верблюды (
    id INT PRIMARY KEY,
    FOREIGN KEY (id) REFERENCES Вьючные_животные(id) ON DELETE CASCADE
);

CREATE TABLE Ослы (
    id INT PRIMARY KEY,
    FOREIGN KEY (id) REFERENCES Вьючные_животные(id) ON DELETE CASCADE
);

-- Заполнение таблиц
INSERT INTO Домашние_животные (тип_животного, имя, команда, дата_рождения) VALUES 
('Собака', 'Бобик', 'Сидеть, Лежать, Голос', '2020-05-15'),
('Кошка', 'Мурка', 'Кис-кис', '2021-02-20'),
('Хомяк', 'Пушистик', 'Крутить колесо', '2022-07-10');

INSERT INTO Собаки (id) VALUES (1);
INSERT INTO Кошки (id) VALUES (2);
INSERT INTO Хомяки (id) VALUES (3);

INSERT INTO Вьючные_животные (тип_животного, имя, команда, дата_рождения) VALUES 
('Лошадь', 'Буран', 'Галоп, Шаг', '2019-03-12'),
('Верблюд', 'Горбун', 'Идти, Стоять', '2018-11-05'),
('Осел', 'Упрямец', 'Возить груз', '2020-09-18');

INSERT INTO Лошади (id) VALUES (1);
INSERT INTO Верблюды (id) VALUES (2);
INSERT INTO Ослы (id) VALUES (3);

-- Удаление верблюдов
DELETE FROM Вьючные_животные WHERE тип_животного = 'Верблюд';

-- Объединение лошадей и ослов
CREATE TABLE Лошади_и_ослы AS
SELECT * FROM Вьючные_животные 
WHERE тип_животного IN ('Лошадь', 'Осел');

-- Создание таблицы молодых животных
CREATE TABLE Молодые_животные AS
SELECT *, 
       CONCAT(
           TIMESTAMPDIFF(YEAR, дата_рождения, CURDATE()), ' года ',
           TIMESTAMPDIFF(MONTH, дата_рождения, CURDATE()) % 12, ' месяцев'
       ) AS возраст
FROM (
    SELECT * FROM Домашние_животные
    UNION
    SELECT * FROM Вьючные_животные
) AS все_животные
WHERE дата_рождения BETWEEN DATE_SUB(CURDATE(), INTERVAL 3 YEAR) 
                        AND DATE_SUB(CURDATE(), INTERVAL 1 YEAR);

-- Объединение всех таблиц
CREATE TABLE Все_животные AS
SELECT 'Домашние' AS категория, тип_животного, имя, команда, дата_рождения 
FROM Домашние_животные
UNION ALL
SELECT 'Вьючные' AS категория, тип_животного, имя, команда, дата_рождения 
FROM Вьючные_животные;
