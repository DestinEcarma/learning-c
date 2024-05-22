#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) (a > b ? a : b);

typedef char String[20];

typedef struct {
	int hour;
	int minute;
} MyTime;

typedef struct {
	char type;
	String plate_num;
	String color;
	String model;
} Vehicle;

typedef struct {
	Vehicle vehicle;
	MyTime time_in;
	MyTime time_out;
} ParkingInfo;

typedef struct {
	ParkingInfo *slot;
	int count;
	int max;
} ParkingArea, ParkingHistory;

void init_parking_area(ParkingArea *parking_area, int size) {
	parking_area->slot = (ParkingInfo *)calloc(size, sizeof(ParkingInfo));
	parking_area->count = 0;
	parking_area->max = size;
}

ParkingInfo create_parking_info(Vehicle vehicle, MyTime time_in, MyTime time_out) {
	return (ParkingInfo){vehicle, time_in, time_out};
}

Vehicle create_vehicle(char type, String plate_num, String color, String model) {
	Vehicle vehicle = {type};

	strcpy(vehicle.plate_num, plate_num);
	strcpy(vehicle.color, color);
	strcpy(vehicle.model, model);

	return vehicle;
}

MyTime create_my_time(int hour, int minute) {
	return (MyTime){hour, minute};
}

void display_parking_area(ParkingArea *parking_area) {
	int available_slot = MAX(parking_area->max - parking_area->count, 0);

	printf("SLOT NO. | STATUS -> (Available Slot: %d)\n", available_slot);

	for (int i = 0; i < parking_area->max; i++) {
		Vehicle *temp = &(parking_area->slot + i)->vehicle;

		printf("%d\t", i + 1);

		if (temp->type) {
			printf(" | %s - %s - %s\n", temp->model, temp->color, temp->plate_num);
		} else {
			printf(" | available\n");
		}
	}
}

bool add_park_in(ParkingArea *parking_area, Vehicle vehicle, MyTime time_in, int slot_num) {
	if (parking_area->count >= parking_area->max) return false;
	if (slot_num < 0 || slot_num > parking_area->max) return false;

	ParkingInfo *temp = parking_area->slot + slot_num;
	if (temp->vehicle.type) return false;

	temp->vehicle = vehicle;
	temp->time_in = time_in;
	memset(&temp->time_out, 0, sizeof(MyTime));

	parking_area->count++;

	return true;
}

bool add_park_out(ParkingArea *parking_area, MyTime time_out, String plate_num) {
	for (int i = 0; i < parking_area->max; i++) {
		ParkingInfo *temp_parking_info = parking_area->slot + i;
		MyTime *temp_time_in = &temp_parking_info->time_in;
		MyTime *temp_time_out = &temp_parking_info->time_out;

		if (!(temp_time_in->hour + temp_time_in->minute)) continue;
		if (temp_time_out->hour + temp_time_out->minute) continue;

		Vehicle *temp_vehicle = &temp_parking_info->vehicle;

		if (strcmp(temp_vehicle->plate_num, plate_num)) continue;

		*temp_time_out = time_out;

		return true;
	}

	return false;
}

bool check_out_vehicle(ParkingArea *parking_area, ParkingHistory *parking_history, String plate_num) {
	for (int i = 0; i < parking_area->max; i++) {
		ParkingInfo *temp_parking_info = parking_area->slot + i;
		MyTime *temp_time_in = &temp_parking_info->time_in;
		MyTime *temp_time_out = &temp_parking_info->time_out;

		if (!(temp_time_in->hour + temp_time_in->minute)) continue;

		Vehicle *temp_vehicle = &temp_parking_info->vehicle;

		if (strcmp(temp_vehicle->plate_num, plate_num)) continue;

		parking_history->slot[i] = *temp_parking_info;

		memset(temp_time_in, 0, sizeof(MyTime));
		memset(temp_vehicle, 0, sizeof(Vehicle));

		parking_area->count--;
		parking_history->count++;

		return true;
	}

	return false;
}

ParkingHistory create_parking_history(int max) {
	ParkingHistory parking_history;

	parking_history.slot = (ParkingInfo *)calloc(max, sizeof(ParkingInfo));
	parking_history.count = 0;
	parking_history.max = max;

	return parking_history;
}

void print_parking_receipt(ParkingInfo *parking_info) {
	MyTime *temp_time_in = &parking_info->time_in;
	MyTime *temp_time_out = &parking_info->time_out;
	Vehicle *temp_vehicle = &parking_info->vehicle;

	MyTime difference = {temp_time_out->hour - temp_time_in->hour, temp_time_out->minute - temp_time_in->minute};

	float diff_total_hours = difference.hour + ((float)difference.minute / 60);

	float first_3_hours = diff_total_hours > 3 ? 3 : diff_total_hours;
	float after_3_hours = diff_total_hours > 3 ? diff_total_hours - 3 : 0;

	float initial_charge;
	float additional_charge;

	switch (temp_vehicle->type) {
		case 'A':
			initial_charge = 30 * first_3_hours;
			break;
		case 'B':
			initial_charge = 40 * first_3_hours;
			break;
		case 'C':
			initial_charge = 100 * first_3_hours;
			break;
	}

	additional_charge = after_3_hours * 10;

	printf("TYPE: %c\n", temp_vehicle->type);
	printf("VEHICLE: %s - %s - %s\n", temp_vehicle->plate_num, temp_vehicle->color, temp_vehicle->model);
	printf("TIME IN: %02d:%02d\n", temp_time_in->hour, temp_time_in->minute);
	printf("TIME OUT: %02d:%02d\n", temp_time_out->hour, temp_time_out->minute);
	printf("TOTAL TIME: %02d:%02d\n", temp_time_out->hour - temp_time_in->hour);
	printf("Initial Charge (first 3 hours): Php %02.2f\n", initial_charge);
	printf("Additional Charge (after 3 hours): Php %02.2f\n", additional_charge);
	printf("Total Charge: Php %02.2f\n", initial_charge + additional_charge);
}

int main(void) {
	ParkingArea parking_area;
	init_parking_area(&parking_area, 10);

	ParkingHistory parking_history = create_parking_history(10);

	Vehicle motor1 = create_vehicle('A', "suckad", "Green", "Yamaha");
	Vehicle car1 = create_vehicle('B', "catch me", "Black", "Toyota");
	Vehicle car2 = create_vehicle('B', "cumonme", "Yello", "Camaro");

	MyTime time_in = create_my_time(9, 0);
	MyTime time_out = create_my_time(15, 10);

	add_park_in(&parking_area, motor1, time_in, 0);
	add_park_in(&parking_area, car1, time_in, 1);
	add_park_in(&parking_area, car2, time_in, 5);

	display_parking_area(&parking_area);

	add_park_out(&parking_area, time_out, "cumonme");
	check_out_vehicle(&parking_area, &parking_history, "cumonme");

	printf("\n");

	for (int i = 0; i < parking_history.max; i++) {
		ParkingInfo *temp = parking_history.slot + i;
		if (!temp->vehicle.type) continue;

		print_parking_receipt(temp);
	}

	return 0;
}
