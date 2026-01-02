#include <stdio.h> 
#include <stdbool.h>
#include <unistd.h> 

int vehicle_count = 0; 

bool sensor() {
	int signal;
	printf("Enter 1 if a vehicle is passed (0 to stop detection): ");
	scanf("%d", &signal);
	return signal == 1;
}

int count_vehicles() {
	bool vehicle_detected;

	printf("\nStarting vehicle detection...\n");
	while (true) {
		vehicle_detected = sensor();
		if (vehicle_detected) {
			vehicle_count++;

			printf("\nVehicle passed! Total vehicles: %d\n", vehicle_count);
		} else {
			break;
		}
	}
	return vehicle_count;
}

void adjust_time() {
	int green_light_duration;

	if (vehicle_count == 0) {
		green_light_duration = 5;
	} else if (vehicle_count <= 5) {
		green_light_duration = 10;
	} else if (vehicle_count <= 15) {
		green_light_duration = 20;
	} else {
		green_light_duration = 30;
}

printf("\nGreen light for %d seconds...\n", green_light_duration);

for (int i = green_light_duration; i > 0; i--) {

	printf("%d seconds remaining...\n", i);
	sleep(1);
	}

	printf("Yellow light for 5 seconds...\n");
	sleep(5);
	
	printf("Red light for 10 seconds...\n");
	sleep(10);
	
	}


int main() {
	
	printf("Traffic light control system started...\n");

	while (1) {

		vehicle_count = 0;

		count_vehicles();

		adjust_time();
	
		printf("\nStarting new cycle...\n");
	}

	return 0;

}