# 42_get_next_line


# Get Next Line #
## Чтение строки из файлового дескриптора слишком утомительно ##
Резюме: цель этого проекта - заставить вас закодировать функцию, которая возвращает строку, которая заканчивается \n и читается из файлового дескриптора.

# Содержание #

1. Цели
2. Общие инструкции
3. Обязательная часть
4. Бонусная часть

# Глава 1 #

## Цели ##

Этот проект не только позволит вам добавить в свою коллекцию очень удобную функцию,но это также позволит вам изучить очень интересную новую концепцию программирования на C - статические переменные.

# Глава 2 #

## Общие инструкции ##

* Ваш проект должен быть написан в соответствии с Нормой. Если у вас есть бонус файлы/функции, они включены в проверку нормы, и вы получите 0, если есть нарушения нормы;
* Ваши функции не должны завершаться неожиданно (SegFault, BusError, double free и т. д.), кроме неопределенного поведения. Если это произойдет, ваш проект будет считается нефункциональным и получит 0 во время оценки;
* Всё пространство памяти, выделенное кучей, должно быть должным образом освобождено при необходимости. Утечек не должно быть;
* Если предмет требует этого, вы должны отправить Makefile, который скомпилирует ваши исходные файлы в требуемый вывод с флагами -Wall, -Wextra и -Werror и ваш Makefile не должен повторно связываться;
* Ваш Makefile должен содержать как минимум правила $(NAME), all, clean, fclean и re;
* Чтобы выполнить бонусы в проекте, вы должны включить правило bonus в свой Makefile, который добавит все различные заголовки, библиотеки или функции, запрещенные на основной части проекта. Бонусы должны быть в другом файле _bonus.{C / h}. Оценка обязательной и бонусной части проводится отдельно;
* Если ваш проект позволяет вам использовать ваш libft, вы должны скопировать его исходный код и его связанный Makefile в папке libft со связанным Makefile. Ваш проект Makefile должен скомпилировать библиотеку, используя свой Makefile, а затем скомпилировать проект;
* Отправьте свою работу в назначенный репозиторий git. Только работа в репозитории git будут оценены. Если Deepoughtt назначено оценивать вашу работу, она будет выполнена после ваших экспертных оценок. Если в каком-либо разделе вашей работы во время  выставлении оценок DeepThread оценка будет отрицательной, то проверка остановится.

# Глава 3 #

## Обязательная часть ##

Название программы  | get_next_line
:-------------------|:---------------
Прототип функции        | int get_next_line(int fd, char **str);
Файлы для сдачи         | get_next_line.c, get_next_line_utils.c, get_next_line.h
Параметры			    | №1 - файловый дескриптор; №2 - то, что было прочитано
Возвращаемое значение   | 1: строка прочитана; 0: достигнут EOF; -1: произошла ошибка 
Разрешенные внешние функции | read, malloc, free
Описание			    | Напишите функцию, которая возвращает строку, прочитанную из дескриптора файла без новой строки.


* Вызов функции get_next_line в цикле позволит вам прочитать текст доступный в дескрипторе файла по одной строке до EOF;
* Убедитесь, что ваша функция работает нормально, когда она читает из файла и когда оначитает со стандартного ввода;
* libft не разрешена для этого проекта. Вы должны добавить файл get_next_line_utils.cкоторый будет содержать функции, необходимые для работы вашего get_next_line;
* Ваша программа должна компилироваться с флагом -D BUFFER_SIZE = xx. который будет использоваться как размер буфера для вызовов чтения в вашей get_next_line. Это значение будет изменено вашими оценщиками и муленеттом;
* Компиляция будет производиться следующим образом: gcc -Wall -Wextra -Werror -D BUFFER_SIZE = 32get_next_line.c get_next_line_utils.c;
* Ваше чтение должно использовать BUFFER_SIZE, определенный во время компиляции, чтобы читать из файл или из stdin;
* В заголовочном файле get_next_line.h у вас должен быть как минимум прототип функция get_next_line;

> Ваша функция все еще работает, если значение BUFFER_SIZE равно 9999? А если значение BUFFER_SIZE равно 1? А 10 000 000? Ты знаешь почему?

> Вы должны стараться читать как можно меньше каждый раз, когда вызывается get_next_line. Если вы столкнулись с новой строкой, вы должны вернуть текущую строку. Не читайте весь файл целиком, а затем обрабатывайте каждую строку.

> Не сдавайте свой проект без тестирования. Есть много тестов, которые нужно выполнить, охватите свои базы. Попробуйте прочитать из файла, из перенаправления, из стандартного ввода. Как ведет себя ваша программа, когда вы отправляете новую строку в стандартный вывод? И CTRL-D?

* Мы считаем, что get_next_line имеет неопределенное поведение, если между двумя вызовамитот же дескриптор файла переключается на другой файл до того, как EOF будет достигнут напервый fd.
* lseek - недопустимая функция. Чтение файла необходимо производить только один раз.
* Наконец, мы считаем, что get_next_line имеет неопределенное поведение при чтении из двоичного файла. Однако при желании вы можете сделать такое поведение последовательным.
* Глобальные переменные запрещены.

> Хорошим началом было бы узнать, что такое статическая переменная: https://en.wikipedia.org/wiki/Static_variable

# Глава 4 #

## Бонусная часть ##

Проект get_next_line прост и оставляет очень мало места для бонусов, но я уверен, что у вас много воображения. Если вы отлично справились с обязательной частью, то обязательно заполните эту бонусную часть, чтобы идти дальше. Повторяю, никакой бонус не будет принят во внимание, если обязательная часть не идеальна. Включите все 3 исходных файла с _bonus для этой части.

* Для достижения успеха get_next_line с одной статической переменной.
* Чтобы иметь возможность управлять несколькими файловыми дескрипторами с помощью get_next_line. Например, если файловые дескрипторы 3, 4 и 5 доступны для чтения, то вы можете вызвать get_next_line один раз на 3, один раз на 4, еще раз на 3, затем один раз на 5 и т.д. без потери потока чтения для каждого из дескрипторов.