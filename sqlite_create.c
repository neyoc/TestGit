#include <sqlite3.h>
#include <stdio.h>

int main(void) {

  sqlite3 *db;
  char *err_message = 0;

  int rc = sqlite3_open("test.db", &db);

  if (rc != SQLITE_OK) {

    fprintf(stderr, "Can not open the database: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 1;
  } else {
    fprintf(stdout, "Database Opened successfully\n");
  }

  char *sql_query = "DROP TABLE IF EXISTS STUDENTS;"
                    "CREATE TABLE STUDENTS(Id INT PRIMARY KEY NOT NULL, Name TEXT, Surname TEXT);";

  rc = sqlite3_exec(db, sql_query, 0, 0, &err_message);

  if (rc != SQLITE_OK ) {

    fprintf(stderr, "SQL error: %s\n", err_message);

    sqlite3_free(err_message);
    sqlite3_close(db);

    return 1;
  } else {
    fprintf(stdout, "Table STUDENTS created successfully\n");
  }

  sqlite3_close(db);

  return 0;
}
