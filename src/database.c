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

  char *sql = (char*)malloc(100 * sizeof(char));

  sql = strcpy(sql, "CREATE TABLE aboutWorkshop (id INT PRIMARY KEY, address TEXT); ");


  sql = strcat(sql, "CREATE TABLE masters "
                    "(name TEXT,"
                    " workshopId INT,"
                    " id INT PRIMARY KEY,"
                    " FOREIGN KEY (workshopId) REFERENCES aboutWorkshop(id)); ");

  sql = strcat(sql, "CREATE TABLE cars "
                    "(workshopID INT,"
                    " carName TEXT,"
                    " FOREIGN (workshopId) REFERENCES aboutWorkshop(id)); ");

  sql = strcat(sql, "CREATE TABLE complitedWork "
                    "(workshopID INT,"
                    " receiptDate DATE,"
                    " repairComplitionDate DATE,"
                    " VINnumber INT,"
                    " repairType TEXT,"
                    " cost  MONEY,"
                    " master INT,"
                    " FOREIGN (workshopId) REFERENCES aboutWorkshop(id),"
                    " FOREIGN (master) REFERENCES aboutWorkshop(id)); ");

  sql = strcat(sql, "CREATE TABLE repairedCars "
                    "(carID TEXT PRIMARY KEY,"
                    " carName TEXT,"
                    " yearOfProduction TEXT,"
                    " ownerName TEXT,"
                    " VINnumber INT,"
                    " ownerAdress TEXT,"
                    " FOREIGN (VINnumber) complitedWork(VINnumber)); ");


  rc = sqlite3_exec(db, sql, NULL, NULL, NULL);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
  } else {
    printf("Table created successfully\n");
  }

  sqlite3_close(db);
  free(sql);
}