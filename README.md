# Sort_Algo

Hello Mr Bogdan. We want to represent to you our great work in algorithm science!!!
___
# Содержание
- [ ] 1) [Insertion Sort](#Insertion) 
1) [Selection Sort](#Selection)
1) [Bubble Sort](#Bubble)
1) [Gnome Sort](#Gnome)
1) [Cocktail Sort](#Cocktail)
1) [Heap Sort](#Heap)
1) [Quick Sort](#Quick)
1) [Merge Sort](#Merge)
1) [Tree Sort](#Tree)
1) [Comb Sort](#Comb)
1) [Shell Sort](#Shell)
1) [Bucket Sort](#Bucket)
1) [Pancake Sort](#Pancake)
1) [PSRS Sort](#PSRS)
1) [Patience Sort](#Patience)
1) [Smooth Sort](#Smooth)
1) [Tim Sort](#Tim)
1) [Radix Sort](#Radix)
1) [Sleep Sort](#Sleep)
1) [Stalin Sort](#Stalin)
1) [Bitonic Sort](#Bitonic)

---

## <a id="Insertion">Insertion Sort</a>
Сортировка вставками. Строит отсортированную последовательность, путем постепенного включения элементов из исходного массива.

* Лучший случай - Omega(n)
* Худший случай - O(n^2)
* Средний случай - O(n^2)
* Память - O(1)
* Стабильность - <span style="color:green">YES</span>

## <a id="Selection">Selection Sort</a>
Сортировка выбором. Методом итерации находит минимальный (или максимальный) элемент в неотсортированной части массива и перемещает его в начало (или конец) отсортированной части. Также для этого алгоритма не требуется дополнительной памяти.

* Лучший случай - Omega(n)
* Худший случай - O(n^2)
* Средний случай - O(n^2)
* Память - O(1)
* Стабильность - <span style="color:red">NO</span>

## <a id="Bubble">Bubble Sort</a>
Сортировка пузырьком. Называется так из-за характерного движения элементов, "всплывающих" к верхней части массива.

* Лучший случай - Omega(n)
* Худший случай - O(n^2)
* Средний случай - O(n^2)
* Память - O(1)
* Стабильность - <span style="color:green">YES</span>

## <a id="Gnome">Gnome Sort</a>
Гномья сртировка. Так назван из-за своего поведения: он перемещается по массиву подобно гному, и проверяет, нужно ли два соседних элемента поменять местами. Если нужно, то гном их меняет, иначе движется дальше. Пока не дойдет до конца.

* Лучший случай - Omega(n)
* Худший случай - O(n^2)
* Средний случай - O(n^2)
* Память - O(1)
* Стабильность - <span style="color:green">YES</span>

## <a id="Cocktail">Cocktail Sort</a>
Сортировка перемешиванием. Усовершенствованный вариант сортировки пузырьком. Устраняет её недостатки, также уменьшает число проходов по массиву. В сортировке перемешиванием элементы сравниваются и перемещаются в обоих направлениях (от начала к концу и обратно)

* Лучший случай - Omega(n)
* Худший случай - O(n^2)
* Средний случай - O(n^2)
* Память - O(1)
* Стабильность - <span style="color:green">YES</span>

## <a id="Heap">Heap Sort</a>
Сортировка кучей. Основан на структуре Куча. Очевидно эффективный алгоритм, особенно для массивов с большим колличеством данных.

* Лучший случай - Omega(n log n)
* Худший случай - O(n log n)
* Средний случай - O(n log n)
* Память - O(1)
* Стабильность - <span style="color:red">NO</span>

## <a id="Quick">Quick Sort</a>
Быстрая сортировка( Сортировка Хоара ). Эффективный алгоритм, основанный на принципе "разделяй и властвуй". Работает путем выбора опроного разделителя (pivot) массива на подгруппы, большие pivot, меньшие и равные ему. Затем каждая из групп сортируется рукурсивно. Хороша для больших данных.

* Лучший случай - Omega(n log n)
* Худший случай - O(n^2)
* Средний случай - O(n log n)
* Память - O(log n)
* Стабильность - <span style="color:red">NO</span>

## <a id="Merge">Merge Sort</a>
Сортировка слиянием. Эффективный алгоритм, фндаментальный. Работает рекурсивно, допуская сортировку как больших так и небольших объемов данных.

* Лучший случай - Omega(n log n)
* Худший случай - O(n log n)
* Средний случай - O(n log n)
* Память - O(n)
* Стабильность - <span style="color:green">YES</span>

## <a id="Tree">Tree Sort</a>
Сортировка двоичным деревом. Использует структуру двоичного дерева для упорядочивания элементов. Принцип: создание дерева, в котором меньшие элементы находятся в левом поддереве, а большие в правом. Для сортировки - элементы вставляются в дерево. Затем - обход дерева в порядке возрастания, что дает осортированный результат. Хорош для больших данных.

* Лучший случай - Omega(n log n)
* Худший случай - O(n^2)
* Средний случай - O(n log n)
* Память - O(n)
* Стабильность - <span style="color:red">NO</span>

## <a id="Counting">Counting Sort</a>
Сортировка подсчетом. Основана на сортировке Тони Хоара.
k - диапазон значений в массиве.

* Лучший случай - Omega(n + k)
* Худший случай - O(n + k)
* Средний случай - O(n + k)
* Память - O(n + k)
* Стабильность - <span style="color:green">YES</span>

## <a id="Comb">Comb Sort</a>
Сортировка расческой. Улучшенная версия сортировки пузырьком, которая позволяет более эффективно перемещать элементы в массиве.

* Лучший случай - Omega(n log n)
* Худший случай - O(n^2)
* Средний случай - O(n^2)
* Память - O(1)
* Стабильность - <span style="color:red">NO</span>

## <a id="Shell">Shell Sort</a>
Сортировка Шелла. Улучшенный алгоритм сортировки вставками, использующий последовательность инкрементов для эффективной сортировки элементов в массиве.

* Лучший случай - Omega(n log^2 n)
* Худший случай - O(n^2)
* Средний случай - O(n^(1.25))
* Память - O(1)
* Стабильность - <span style="color:red">NO</span>

## <a id="Bucket">Bucket Sort</a>
Сортировка с использованием корзин. Разбивает входный массив на равные интервалы(корзины), распределяет элементы по соответвующим корзинам, затем отдельно сортирует каждую корзину(часто с использованием другого сортировочного алгоритма или рекурсивно применяя сортировку с использованием корзин)

* Лучший случай - Omega(n + k)
* Худший случай - O(n^2)
* Средний случай - O(n)
* Память - O(n + k)
* Стабильность - <span style="color:green">YES</span>

## <a id="Pancake">Pancake Sort</a>
Алгоритм сортировки с помощью одной операции — переворота элементов последовательности до какого-то индекса (префикса последовательности).

* Лучший случай - Omega(n)
* Худший случай - O(n^2)
* Средний случай - O(n^2)
* Память - O(1)
* Стабильность - <span style="color:green">YES</span>

## <a id="PSRS">PSRS Sort</a>
параллельная быстрая сортировка которая имеет два преимущества по сравнению с быстрой сортировкой:\
1)сохраняет размер списка более сбалансированным на протяжении всего процесса \
2)избегает повторных перестановок ключей\
(здесь p - кол-во процессоров)
* Лучший случай - Omega(n*log(n/p) / p)
* Худший случай - O(n*log(n/p) / p)
* Средний случай - O(n*log(n/p) / p)
* Память - O(p^2)
* Стабильность - <span style="color:red">NO</span>

## <a id="Patience">Patience Sort</a>
Раскладывает элементы из списка в минимальное количество упорядоченных стопок, после чего собирает минимальные элементы.

* Лучший случай - Omega(n)
* Худший случай - O(n log n)
* Средний случай - O(n log n)
* Память - O(n)
* Стабильность - <span style="color:red">NO</span>

## <a id="Smooth">Smooth Sort</a>
Рзновидность пирамидальной сортировки.Преимущество в том, что её сложность приближается к O(n), если входные данные частично отсортированы.\
Здесь используется не двоичная куча, а специальная, полученная с помощью чисел Леонардо. Куча состоит из последовательности куч, размеры которых равны одному из чисел Леонардо, а корни хранятся в порядке возрастания.\
Преимущества таких специальных куч перед двоичными состоят в том, что если последовательность отсортирована, её создание и разрушение займёт O(n) времени

* Лучший случай - Omega(n)
* Худший случай - O(n log n)
* Средний случай - O(n log n)
* Память - O(1)
* Стабильность - <span style="color:green">YES</span>

## <a id="Tim">Tim Sort</a>
Гибридный алгоритм сортировки, который сочетает сортировку вставками и сортировку слиянием. \
На массивах данных, которые содержат упорядоченные подмассивы, алгоритм показывает себя намного лучше других сортировок.

* Лучший случай - Omega(n)
* Худший случай - O(n log n)
* Средний случай - O(n log n)
* Память - O(n)
* Стабильность - <span style="color:green">YES</span>

## <a id="Radix">Radix Sort</a>
Алгоритм несравнительной сортировки (все значения одинаковой длины), позволяет избежать сравнения, создавая и распределяя элементы по группам в соответствии с их разрядом.\
Процесс повторяется с каждым разрядом пока не будут пройдены все разряды. Существует реализаия прохода с левой стороны (***MSD***) и с правой (***LSD***).\
p - длина числа
* Лучший случай - Omega(n * p)
* Худший случай - O(n * p)
* Средний случай - O(n * p)
* Память - O(n + p)
* Стабильность - <span style="color:green">YES</span>

## <a id="Sleep">Sleep Sort</a>
Возвращаем каждый численный элемент со значением t через t секунд.

* Лучший случай - Omega(1)
* Худший случай - O(inf)
* Средний случай - O(inf)
* Память - O(1)
* Стабильность - <span style="color:red">NO</span>

## <a id="Stalin">Stalin Sort</a>
Проходим циклом по массиву, сравнивая текущий элемент со следующим.
Если следующий элемент меньше текущего, то удаляем его.

* Лучший случай - Omega(n)
* Худший случай - O(n)
* Средний случай - O(n)
* Память - O(1)
* Стабильность - <span style="color:green">YES</span> ( <span style="color:red">NO</span> )

## <a id="Bitonic">Bitonic Sort</a>
На вход подается последовательность чисел, размерностью в степень двойки.\
Сначала строится Битонная последовательность из исходной (это последовательность, которая сначала монотонно не убывает, а затем монотонно не возрастает, либо приводится к такому виду в результате циклического cдвига)\
Каждое множество неотсортированных элементов можно считать множеством битонных последовательностей, состоящих из двух элементов. Сам алгоритм Битонной сортировки предполагает работу с каждой из половин входящего множества элементов.

Чтобы превратить любую _битонную_ последовательность в отсортированную, нужно:

    -Разделить последовательность пополам, попарно сравнить элементы x[i] и x[n / 2 + i], меняя их местами, если элемент из первой половины больше(или меньше).
    -Рекурсивно выполнить сортировку над каждой из получившихся половин.

* Лучший случай - Omega(log^2(n))
* Худший случай - O(log^2(n))
* Средний случай - O(log^2(n))
* Память - O(1)
* Стабильность - <span style="color:green">YES</span>


\
\
\
\
\
\
\
\
\
\
\
![ass](sad.png)
