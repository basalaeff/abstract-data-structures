# Лабораторная работа №1: Абстрактные структуры данных

## Описание

Проект является реализацией лабораторной работы 1 по теме «Абстрактные структуры данных» курса «Программирование».
Цель работы — изучить алгоритмы формирования и работы с абстрактными структурами данных, такими как массив, односвязный и двусвязный списки, стек, очередь и дерево (Complete Binary Tree).

## Задачи

1. Разработать алгоритмы работы с абстрактными структурами данных.
2. Написать программу на одном из языков: C, C++, Rust, Go.
3. Протестировать программу на различных исходных данных.
4. Модифицировать программу по запросу преподавателя и добавить новые операции с данными.

## Реализованные структуры данных и операции над ними

**Массив (A)**:

- A1 Добавление элемента (в конец массива): `AADD value`
```bash
./dbms --file data/Adata.txt --query 'AADD Black'
```
Тестовые данные
```bash
./dbms --file data/Adata.txt --query 'AADD Black'
./dbms --file data/Adata.txt --query 'AADD White'
./dbms --file data/Adata.txt --query 'AADD Red'
./dbms --file data/Adata.txt --query 'AADD Green'
./dbms --file data/Adata.txt --query 'AADD Blue'
```
- A2 Добавление элемента (по индексу): `AINSERT index value`
```bash
./dbms --file data/Adata.txt --query 'AINSERT 2 Yellow'
```
- A3 Получение элемента (по индексу): `AGET index`
```bash
./dbms --file data/Adata.txt --query 'AGET 2'
```
- A4 Удаление элемента (по индексу): `ADEL index`
```bash
./dbms --file data/Adata.txt --query 'ADEL 2'
```
- A5 Замена элемента (по индексу): `AREPLACE index value`
```bash
./dbms --file data/Adata.txt --query 'AREPLACE 2 Grey'
```
- A6 Длина массива: `ALEN`
```bash
./dbms --file data/Adata.txt --query 'ALEN'
```
- A7 Чтение: `PRINT`
```bash
./dbms --file data/Adata.txt --query 'PRINT'
```

**Односвязный список (B)**:

- B1 Добавление элемента (в голову): `BADDHEAD value`
```bash
./dbms --file data/Bdata.txt --query 'BADDHEAD Omsk'
```
Тестовые данные
```bash
./dbms --file data/Bdata.txt --query 'BADDHEAD Omsk'
./dbms --file data/Bdata.txt --query 'BADDHEAD Podolsk'
./dbms --file data/Bdata.txt --query 'BADDHEAD Novokuznetsk'
./dbms --file data/Bdata.txt --query 'BADDHEAD Norilsk'
```
- B2 Добавление элемента (в хвост): `BADDTAIL value`
```bash
./dbms --file data/Bdata.txt --query 'BADDTAIL Kemerovo'
```
Тестовые данные
```bash
./dbms --file data/Bdata.txt --query 'BADDTAIL Kemerovo'
./dbms --file data/Bdata.txt --query 'BADDTAIL Moscow'
./dbms --file data/Bdata.txt --query 'BADDTAIL Tomsk'
./dbms --file data/Bdata.txt --query 'BADDTAIL Voronezh'
```
- B3 Удаление элемента (из головы): `BDELHEAD`
```bash
./dbms --file data/Bdata.txt --query 'BDELHEAD'
```
- B4 Удаление элемента (из хвоста): `BDELTAIL`
```bash
./dbms --file data/Bdata.txt --query 'BDELTAIL'
```

**Двусвязный список (C)**:

- C1 Добавление элемента (в голову): `CADDHEAD value`
```bash
./dbms --file data/Cdata.txt --query 'CADDHEAD Australia '
```
Тестовые данные
```bash
./dbms --file data/Cdata.txt --query 'CADDHEAD Australia'
./dbms --file data/Cdata.txt --query 'CADDHEAD Armenia'
./dbms --file data/Cdata.txt --query 'CADDHEAD Albania'
./dbms --file data/Cdata.txt --query 'CADDHEAD Japan'
```
- C2 Добавление элемента (в хвост): `CADDTAIL value`
```bash
./dbms --file data/Cdata.txt --query 'CADDTAIL UK'
```
Тестовые данные
```bash
./dbms --file data/Cdata.txt --query 'CADDTAIL UK'
./dbms --file data/Cdata.txt --query 'CADDTAIL Russia'
./dbms --file data/Cdata.txt --query 'CADDTAIL USA'
./dbms --file data/Cdata.txt --query 'CADDTAIL France'
```
- C3 Удаление элемента (из головы): `CDELHEAD`
```bash
./dbms --file data/Cdata.txt --query 'CDELHEAD'
```
- C4 Удаление элемента (из хвоста): `CDELTAIL`
```bash
./dbms --file data/Cdata.txt --query 'CDELTAIL'
```

**Стек (D)**:

- D1 Добавление элемента: `DPUSH value`
```bash
./dbms --file data/Ddata.txt --query 'DPUSH Cherry'
```
Тестовые данные
```bash
./dbms --file data/Ddata.txt --query 'DPUSH Cherry'
./dbms --file data/Ddata.txt --query 'DPUSH Lemon'
./dbms --file data/Ddata.txt --query 'DPUSH Watermelon'
./dbms --file data/Ddata.txt --query 'DPUSH Rasberry'
```
- D2 Удаление элемента: `DPOP`
```bash
./dbms --file data/Ddata.txt --query 'DPOP'
```
- D3 Чтение: `PRINT`
```bash
./dbms --file data/Ddata.txt --query 'PRINT'
```