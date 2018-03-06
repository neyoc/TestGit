#include <sqlite3.h>
#include <stdio.h>

int callback(void *not_used, int argc, char **argv,
             char **column_name) {

  not_used = 0;

  for (int i = 0; i < argc; i++) {

    printf("%s = %s\n", column_name[i], argv[i] ? argv[i] : "NULL");
  }

  printf("\n");

  return 0;
}

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

  char *sql_query = "SELECT * FROM STUDENTS;" ;

  rc = sqlite3_exec(db, sql_query, callback, 0, &err_message);

  if (rc != SQLITE_OK ) {

    fprintf(stderr, "SQL error: %s\n", err_message);

    sqlite3_free(err_message);
    sqlite3_close(db);

    return 1;
  } else {
    fprintf(stdout, "Data fetched successfully from Table STUDENTS\n");
  }

  sqlite3_close(db);

  return 0;
}
