#include <stdio.h>
int main()
{

    printf("Enter the number of slots needed in the array: ");
    int size;
    scanf("%d", &size);

    //array of items
    struct inventoryItem *inventory; //use pointer to item
    inventory =(struct inventoryItem *) malloc(sizeof(struct inventoryItem)*size); //create array to store inventoryItem with size 'size'

    //array of index
    int *indexArray = (int*) malloc(sizeof(int)*size); //not sure if this is right

    //fill array contents
    for(int i = 0; i < size; i++)
    {
        printf("Enter item %d number: ", i);
        scanf("%d", &inventory[i].);

        printf("Enter item %d stock: ", i);
        scanf("%d", &inventory[i].itemsInStock);

        printf("Enter item %d cost: ", i);
        scanf("%f", &inventory[i].cost);

        printf("Enter item %d price: ", i);
        scanf("%f", &inventory[i].retailPrice);
    }

    for(int i = 0; i < size; i++)
    {
        printf("Item %d number: %d\n", i, inventory[i].itemNumber);
        printf("Item %d stock: %d\n", i, inventory[i].itemsInStock);
        printf("Item %d cost: %f\n", i, inventory[i].cost);
        printf("Item %d retail price: %f\n", i, inventory[i].retailPrice);
    }

    //stuck here

    //struct inventoryItem *header = inventory; //error here
    for(int i = 0; i < size; i++)
    {
        //indexArray[i] = inventory[i];
    }



}
