
单条可行路径，自连同，首次跳不上去


Position_arr find_first();

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