/* policy based ds */
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds; 
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
ordered_set<int> X;
/* 
	find_by_order() - Returns an iterator to the k-th largest element (counting from zero)
	order_of_key()  - Number of items in a set that are strictly smaller than our item.
*/
