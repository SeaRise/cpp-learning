- 关联容器
  - 有序: `map, set, multimap, multiset`
  - 无序: `unordered_map, unordered_set, unordered_multimap, unordered_multiset`
- pair, 类似java里常用的Pair
```
        vec.emplace_back(s, i);
        vec.push_back(std::make_pair(s, i));
        vec.push_back(std::pair<std::string, int>(s, i));
        vec.push_back({s, i});
```
- key_type, value_type
```
map<A, B>::key_type = A
map<A, B>::mapped_type = B
map<A, B>::value_type = pair<const A, B>
set<A>::key_type / value_type = A
```
- 操作
  - insert, 返回pair<iter, bool>或iter， 不更新
  - erase, 返回bool.
  - `[x]`, 类似getOrCreate, 如果找不到会对value做值初始化
  - `[x] = y`, insertOrUpdate.
  - `at(x)`, 找不到报错.
  - find, 找存在否.
  - count， 计数.
  - 范围查找: `lower_bound, upper_bound, equal_range`
- 无序(hash)容器特有操作
  - bucket(k), k在哪个bucket
  - (c)begin(k), (c)end(k), 返回bucket的iterator.