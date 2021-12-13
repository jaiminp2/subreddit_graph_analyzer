#include "../include/graphTraversal.h"

GraphTraversal::Iterator::Iterator(std::string start_subreddit, DirectedGraph *graph, GraphTraversal *traversal) : start_subreddit_(start_subreddit), graph_(graph), traversal_(traversal), isEnd(false)
{
    dist = 0;
    current_subreddit_ = start_subreddit_;
}

GraphTraversal::Iterator::Iterator():isEnd(true)
{

}

GraphTraversal::Iterator &GraphTraversal::Iterator::operator++()
{
    if(traversal_->queue.empty()){
        isEnd = true;
        return *this;
    }
    while(visited_subreddits.find(traversal_->queue.front().first.getDestination()) != visited_subreddits.end()){
        traversal_->queue.pop();
    }

    current_subreddit_ = traversal_->queue.front().first.getDestination();
    dist = traversal_->queue.front().second;

    traversal_->queue.pop();

    list<Edge> available_edges = graph_->GetEdges(current_subreddit_);
    for(Edge edge: available_edges){    
            traversal_->queue.push(std::make_pair(edge,dist+1));
       
    }    
        visited_subreddits[current_subreddit_] = dist;
        return *this;
}


std::string GraphTraversal::Iterator::operator*()
{
        return current_subreddit_;
}

bool GraphTraversal::Iterator::operator!=(const GraphTraversal::Iterator& other){
        return this->isEnd == other.isEnd;
}

GraphTraversal::GraphTraversal(DirectedGraph* graph, std::string start_subreddit):start_subreddit_(start_subreddit),graph_(graph)
{  
        for(Edge edge: graph_->GetEdges(start_subreddit_)){
        queue.push(std::make_pair(edge,1));
    }
}

GraphTraversal::Iterator GraphTraversal::begin(){
  return GraphTraversal::Iterator(start_subreddit_,graph_,this);
}

GraphTraversal::Iterator GraphTraversal::end(){
  return GraphTraversal::Iterator();
}

int GraphTraversal::Iterator::getDistanceFromSource(){
    return dist;
}
