# Traffic-Intersection-Problem
In the traffic intersection problem, vehicles are trying to pass through an intersection of two roads, one north/south, the other east/west, without colliding. Each vehicle arrives at the intersection from one of four directions (north, south, east, or west), called it’s origin . It is trying to pass through the intersection and exit in some direction other than its origin,
called it’s destination.

Each arriving vehicle is simulated by a thread, and the intersection is a critical section. Each vehicle (thread) enters the intersection (critical section) and eventually leaves. However, you may not change this file in any way. The vehicle simulation works by creating a fixed number of concurrent threads. 
                        Each thread simulates a sequence of vehicles attempting to pass through the intersection. In a loop, each thread
generates a random vehicle (randomly choosing an origin and destination for the vehicle) and then enters and leaves the critical section to simulate the vehicle passing through the intersection. Threads then sleep for a configurable period of time before generating another random vehicle and repeating the process. Each thread simulates one vehicle at a time.
                       However, since there are multiple concurrent threads, there may be multiple vehicles attempting to enter the critical section (intersection) cncurrently.
                       
Your job is to synchronize the vehicles so that they do not collide in the intersection. Informally, it is OK for more than one vehicle to be in the intersection at the same time as long as their paths will not result in a
collision. 
           For example, it is OK for a vehicle that  is traveling from north to south to share the intersection with another
vehicle that is traveling from south to north, but not with one that is traveling from east to west.
For the purposes of this assignment, we’ve codified a specific set of conditions under which vehicles can safely share the intersection (critical section). If two vehicles, Va and Vb , are in the intersection

simultaneously, then at least one of the following must be true:
 Va and Vb entered the intersection from the same direction, i.e., Va
.origin = Vb .origin , or

 Va and Vb are going in opposite directions, i.e.,
Va .origin = Vb .destination and Va .destination = Vb .origin , or

 Va and Vb have different destinations, and at least one of them is
makin g a right turn, e.g., Va is right-turning from north to west, and
Vb is going from south to north.

Note that it is possible for more than two vehicles to be in the intersection
at the same time, as long as all pairs of vehicles satisfy one of the above
conditions.

These conditions are less flexible than what is allowed at some real road intersections. For example, the conditions above do not allow cars
traveling in opposite directions to make left turns concurrently. Nonetheless, for the purposes of this assignment, these somewhat
simplified conditions will serve as our definition of correctness.
