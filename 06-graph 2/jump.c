
#define ISLAND_R 15

//单条可行路径，自连同，首次跳不上去

/*
bool find_first(PtrPos pos_arr, int PosNum, int jump_R, int *res_arr)
{
    int i = 0;
    float jump_r = jump_R;
    float x = 0;
    float y = 0;
    bool is_find = false;

    for( i = 0; i < PosNum; i++) {
        x = pos_arr[i].x_pos;
        y = pos_arr[i].y_pos;
        if(x > (jump_r + ISLAND_R) || x < -(jump_r-ISLAND_R))
            continue;
        if(y > jump_r + ISLAND_R || y < -jump_r-ISLAND_R)
            continue;
        if(sqrt(x^2+y^2) > (jump_r + ISLAND_R)) {
            continue;
        }
        else {
            res_arr[i] = 1;
            is_find = true;
        }
    }

    return is_find;
}
*/

bool can_escape(PtrPos pos_arr, int PosNum, int jump_R, PtrQueue p_queue)
{
    int first_idx = -1;
    
    if(find_first(pos_arr,PosNum,jump_R,p_queue) == false)
        return false;
    while(!Queue_Is_Empty(p_queue))   {
        first_idx = DeQueue(p_queue);
        if(pos_arr[first_idx].visited == 0)
            if(Jump_DFS(&pos_arr[first_idx], pos_arr, posNum, jump_R) == true)
                return true;
    }
    return false;
}

bool find_first(PtrPos pos_arr, int PosNum, int jump_R, PtrQueue p_queue)
{
    int i = 0;
    float jump_r = jump_R;
    float x = 0;
    float y = 0;
    bool is_find = false;

    for( i = 0; i < PosNum; i++) {
        x = pos_arr[i].x_pos;
        y = pos_arr[i].y_pos;
        /*
        if(x > (jump_r + ISLAND_R) || x < -(jump_r-ISLAND_R))
            continue;
        if(y > jump_r + ISLAND_R || y < -jump_r-ISLAND_R)
            continue;
        */
        if(sqrt(x*x+y*y) > (jump_r + ISLAND_R)) {
            continue;
        }
        else {
            Enqueue(i, p_queue);
            is_find = true;
        }
    }

    return !Queue_Is_Empty(p_queue);
}

bool Jump_DFS(PtrPos cur_pos, PtrPos pos_arr, int pos_num, int jump_R)
{
    float x = cur_pos->x_pos;
    float y = cur_pos->y_pos;
    int i = 0;
    cur_pos->visited = 1;

    if(reach_dest(x, y, jump_R))    return true;
    
    for(i = 0; i < pos_num; i++) {
        float dest_x = pos_arr[i].x_pos;
        float dest_y = pos_arr[i].y_pos;
        
        if(pos_arr[i].visited == 0) 
            if(distance(x,y,dest_x,dest_y) < jump_R)
                if(JumpDFS(&pos_arr[i], pos_arr, pos_num, jump_R))    return true;
        
    }
    return false;
}

/*计算(x,y)到(x1,y1)的距离*/
float distance(float x, float y, float x1, float y1)
{
    return(sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1)));
}

bool reach_dest(float x, float y, int jump_R)
{
    float edge = 50-jump_R;
    return(x>edge || x<-edge || y>edge || y<-edge);
}

/*
DFS(V)
{
    Visit(V)
    for(V1 in adjcent(V))
        if(V1 is not visited)
            DFS(V)           
}

bool Jump_DFS(cur_position, jump_dist, position_array)
{
    visited_or_reached(cur_position);        

    if(reach_edge(cur_position)) {
        return true;
    }

    while(aother_pos = find_another_can_reach_but_unreached_position(cur_position, position_arr)) 
        if(Jump_DFS(another_pos, jump_dist, position_array) == true) return true;

    return false;
    
}


bool Jump_DFS_unlink(initial_pos, position_array) {


while(first_pos in find_first(initial_pos, position_array)) {
    if(Jump_DFS(cur_position, jump_dist, position_array)） return true;
}

return false;

}

*/