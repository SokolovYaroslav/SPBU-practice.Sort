# String sorter

Эта программа реализует различные алгоритмы сортировки на примере сортировки строк.

Ниже представлены результаты профилирования:

## Merge sort
|% time|cumulative seconds|self seconds|calls|self ms/call|total ms/call|name|
|---|---|---|---|---|---|---|
| 63.27   |   0.53  |   0.53  |         |          |       | arr_get_array|
| 25.07   |   0.74  |   0.21 | 8486494  |   0.00  |   0.00 | arr_compare_strings|
|  3.58   |   0.77  |   0.03 |  470545  |   0.00  |   0.00 | arr_merge|
|  3.58   |   0.80  |   0.03 |       1  |  30.08  | 270.76 | arr_merge_sort_recurse|
|  0.00   |   0.80  |   0.00 |  104482  |   0.00  |   0.00 | arr_swap|
### Time in Merge sort
|real|user|sys|
|---|---|--|
|0m4.829s|0m4.608s|0m0.212s|

## Quick sort
|% time|cumulative seconds|self seconds|calls|self ms/call|total ms/call|name|
|---|---|---|---|---|---|---|
| 51.68 | 0.67  |   0.67 | 11909043 |   56.42| 56.42|  arr_compare_strings|
| 40.88 | 1.20  |   0.53 |          |        |      | arr_get_array|
|  3.09 | 1.24  |   0.04 |          |        |      |  arr_quick_sort|
|  0.77 | 1.25  |   0.01 |          |        |      |   arr_bubble_sort|
|  0.00 | 1.25  |   0.00 | 2189125  |   0.00 | 0.00 | arr_swap|
### Time in Quick sort
|real|user|sys|
|---|---|---|
|0m5.695s|0m5.328s|0m0.220s|

Исходя из этих результатов можно залючить, что для улучшения быстродействия программы необходимо улучшить метод swap и compare.
