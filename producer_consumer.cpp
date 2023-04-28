#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int mutex = 1;

int num_full = 0;

int num_empty = 10;

int item = 0;

void producer()
{
	mutex--;

	if (num_empty > 0) {
		num_full++;

		num_empty--;

		item++;
		printf("\nProducer produces item %d\n", item);
	}

	mutex++;
}

void consumer()
{
	mutex--;

	if (num_full > 0) {
		num_full--;

		num_empty++;

		printf("\nConsumer consumes item %d\n", item);
		item--;
	}

	mutex++;
}

int main()
{
	int choice;
	bool is_running = true;

	while (is_running) {
		printf("\n1. Press 1 for Producer\n");
		printf("2. Press 2 for Consumer\n");
		printf("3. Press 3 for Exit\n");

		printf("Enter your choice:");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			if ((mutex == 1) && (num_empty != 0)) {
				producer();
			}
			else {
				printf("Buffer is full!\n");
			}
			break;

		case 2:
			if ((mutex == 1) && (num_full != 0)) {
				consumer();
			}
			else {
				printf("Buffer is empty!\n");
			}
			break;

		case 3:
			is_running = false;
			break;

		default:
			printf("Invalid choice! Please try again.\n");
		}
	}

	return 0;
}