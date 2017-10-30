#include <stdio.h>
#include <stdlib.h>

int main()
{
    test_main();
    return 0;
}


struct Position
{
    int x_pos;
    int y_pos;
    int visited;
};

struct Position* PtrPos;

Search_for_route()
{
    firstjump()
    judge = false;

    queue_ptr = find_adjacent_and_not_visited(curPosition, PositionArray);

    for(element in queue) {
        if(reach the edge) {
            deletequeue(queue_ptr);
            return true;
        }
        else(search_for_route(element, PositionArray)) {

        }
    }

}
