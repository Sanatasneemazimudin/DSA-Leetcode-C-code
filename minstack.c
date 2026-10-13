#include <stdlib.h>
#include <limits.h>
typedef struct {
    int values[30000];
    int mins[30000];
    int top;
} MinStack;
MinStack* minStackCreate() {
    MinStack* obj = malloc(sizeof(MinStack));
    obj->top = -1;
    return obj;
}
void minStackPush(MinStack* obj, int val) {
    obj->top++;
    obj->values[obj->top] = val;
    if (obj->top == 0 ||
        val < obj->mins[obj->top - 1])
        obj->mins[obj->top] = val;
    else
        obj->mins[obj->top] = obj->mins[obj->top - 1];
}
void minStackPop(MinStack* obj) {
    if (obj->top >= 0)
        obj->top--;
}
int minStackTop(MinStack* obj) {
    return obj->values[obj->top];
}
int minStackGetMin(MinStack* obj) {
    return obj->mins[obj->top];
}
void minStackFree(MinStack* obj) {
    free(obj);
}