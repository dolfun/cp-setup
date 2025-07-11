# Priority Queue

```cpp
#ifdef __GNUC__
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
namespace pbds = __gnu_pbds;
template <typename T>
using ordered_set = pbds::tree<T, pbds::null_type, less<T>,
  pbds::rb_tree_tag, pbds::tree_order_statistics_node_update>;
using pbds::gp_hash_table;
#endif
```
