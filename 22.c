#include <stdio.h>

typedef union {
    int temp;
    float pres;
    float hum;
} SensorData;

int main() {
    SensorData s;
    int type;

    printf("Sensor type: 1.Temp 2.Pressure 3.Humidity\nChoice: ");
    scanf("%d", &type);

    switch(type) {
        case 1:
            printf("Temperature (int): ");
            scanf("%d", &s.temp);
            printf("Temp: %d\n", s.temp);
            break;
        case 2:
            printf("Pressure (float): ");
            scanf("%f", &s.pres);
            printf("Pressure: %.2f\n", s.pres);
            break;
        case 3:
            printf("Humidity (float): ");
            scanf("%f", &s.hum);
            printf("Humidity: %.2f\n", s.hum);
            break;
        default:
            printf("Invalid!\n");
    }

    return 0;
}
