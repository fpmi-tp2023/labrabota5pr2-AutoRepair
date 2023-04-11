//
// Created by Kirill on 10.04.2023.
//
#include "../include/database.h"

void createDataBase() {
  sqlite3 *db;
  int rc = sqlite3_open("cityService.db", &db);

  if (rc != SQLITE_OK) {
    fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return;
  }

  char
      *sql = "CREATE TABLE aboutWorkshop (id INT PRIMARY KEY, address TEXT);";

  createTable(db, sql, rc);

  sql = "CREATE TABLE masters "
        "(id INT PRIMARY KEY,"
        " name TEXT,"
        " workshopId INT,"
        " FOREIGN KEY (workshopId) REFERENCES aboutWorkshop(id));";

  createTable(db, sql, rc);

  sql = "CREATE TABLE cars "
        "(workshopId INT,"
        " carName TEXT,"
        " FOREIGN KEY (workshopId) REFERENCES aboutWorkshop(id));";

  createTable(db, sql, rc);

  sql = "CREATE TABLE complitedWork "
        "(workshopId INT,"
        " receiptDate DATE,"
        " repairComplitionDate DATE,"
        " VINnumber INT,"
        " repairType TEXT,"
        " cost  MONEY,"
        " master INT,"
        " FOREIGN KEY (workshopId) REFERENCES aboutWorkshop(id),"
        " FOREIGN KEY (master) REFERENCES masters(id));";

  createTable(db, sql, rc);

  sql = "CREATE TABLE repairedCars "
        "(carID TEXT PRIMARY KEY,"
        " carName TEXT,"
        " yearOfProduction TEXT,"
        " ownerName TEXT,"
        " VINnumber INT,"
        " ownerAdress TEXT,"
        " FOREIGN KEY (VINnumber) REFERENCES complitedWork(VINnumber)); ";

  createTable(db, sql, rc);

  sqlite3_close(db);
}


void createTable(sqlite3 *db, char *sql, int rc) {
  rc = sqlite3_exec(db, sql, NULL, NULL, NULL);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
  } else {
    printf("Table created successfully\n");
  }
}