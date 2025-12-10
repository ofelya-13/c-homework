#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[30];
    char surname[30];
    int id;
    float grade;
} Student;

Student* add_student(Student *arr, int *cnt) {
    arr = realloc(arr, (*cnt + 1) * sizeof(Student));
    if (!arr) { printf("Memory error!\n"); exit(1); }

    printf("Name: "); scanf("%s", arr[*cnt].name);
    printf("Surname: "); scanf("%s", arr[*cnt].surname);
    printf("ID: "); scanf("%d", &arr[*cnt].id);
    printf("Grade: "); scanf("%f", &arr[*cnt].grade);

    (*cnt)++;
    return arr;
}

Student* remove_student(Student *arr, int *cnt) {
    int id, i, found = 0;
    printf("ID to remove: "); scanf("%d", &id);
    for (i = 0; i < *cnt; i++)
        if (arr[i].id == id) { found = 1; break; }
    if (!found) { printf("Not found!\n"); return arr; }

    for (int j = i; j < *cnt - 1; j++) arr[j] = arr[j + 1];
    (*cnt)--;
    arr = realloc(arr, (*cnt) * sizeof(Student));
    printf("Removed.\n");
    return arr;
}

void search_student(Student *arr, int cnt) {
    int id, f = 0;
    printf("ID to search: "); scanf("%d", &id);
    for (int i = 0; i < cnt; i++)
        if (arr[i].id == id) { f = 1; 
            printf("%s %s, ID:%d, Grade:%.2f\n",
                arr[i].name, arr[i].surname, arr[i].id, arr[i].grade);
            break;
        }
    if (!f) printf("Not found!\n");
}

void display_students(Student *arr, int cnt) {
    if (cnt == 0) { printf("No students.\n"); return; }
    for (int i = 0; i < cnt; i++)
        printf("%s %s, ID:%d, Grade:%.2f\n",
            arr[i].name, arr[i].surname, arr[i].id, arr[i].grade);
}

void average_grade(Student *arr, int cnt) {
    if (cnt == 0) { printf("No students.\n"); return; }
    float sum = 0;
    for (int i = 0; i < cnt; i++) sum += arr[i].grade;
    printf("Average: %.2f\n", sum / cnt);
}

void save_to_file(Student *arr, int cnt) {
    FILE *f = fopen("group_details.csv","w");
    if (!f) { printf("Cannot open file.\n"); return; }
    for (int i = 0; i < cnt; i++)
        fprintf(f,"%s,%s,%d,%.2f\n", arr[i].name, arr[i].surname, arr[i].id, arr[i].grade);
    fclose(f);
    printf("Saved.\n");
}

Student* read_from_file(Student *arr, int *cnt) {
    FILE *f = fopen("group_details.csv","r");
    if (!f) { printf("File not found.\n"); return arr; }
    char line[100];
    while (fgets(line,sizeof(line),f)) {
        arr = realloc(arr, (*cnt + 1) * sizeof(Student));
        if (!arr) exit(1);
        sscanf(line,"%[^,],%[^,],%d,%f",
            arr[*cnt].name, arr[*cnt].surname, &arr[*cnt].id, &arr[*cnt].grade);
        (*cnt)++;
    }
    fclose(f);
    printf("Loaded.\n");
    return arr;
}

int main() {
    Student *arr = NULL;
    int cnt = 0, choice;

    do {
        printf("\n1.Add 2.Remove 3.Search 4.Display 5.Average 6.Save 7.Load 8.Exit\nChoice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: arr = add_student(arr,&cnt); break;
            case 2: arr = remove_student(arr,&cnt); break;
            case 3: search_student(arr,cnt); break;
            case 4: display_students(arr,cnt); break;
            case 5: average_grade(arr,cnt); break;
            case 6: save_to_file(arr,cnt); break;
            case 7: arr = read_from_file(arr,&cnt); break;
            case 8: break;
            default: printf("Invalid!\n");
        }
    } while(choice != 8);

    free(arr);
    return 0;
}
