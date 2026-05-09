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