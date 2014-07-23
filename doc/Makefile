


自动变量	含义
$@	工作目标的文件名
$%	档案文件成员结构中的文件名
$<	第一个必要条件的文件名
$^	所有必要条件的文件名，用空格隔开
$+	所有必要条件的文件名，用空格隔开，包括重复的文件名
$*	工作目标的主文件名

表3 GNU make内置函数
函数原型	功能描述	样例
$(filter pattern..., text)	filter将text视为一系列被空格隔开的单词，与pattern比较之后，接着会返回符合的单词列表	$(gui_objects): $(filter gui/%.o, $(objects))
	$(filter pattern...,text)	filter-out函数用来选出与模式不相符合的单词	to_compile := $(filter-out %.h, $(all_source))
	$(findstring string..., text)	此函数将会在text搜索string。如果该字符串被找到了，此函数就会返回string；否则，返回空值。	$(findstring /tom/book/zeuux, $(PWD))
$(subst search-string, replace-string, text)	常用来在文件名列表中将一个名换成另外一个扩展名，不带通配符功能	objects := $(subst .c, .o, $(sources))
$(patsubst search-pattern, replace-pattern, text)	replace-pattern中的%被扩展成与模式相符的文字,且search-pattern必须与text的整个值进行匹配	strip-trailing-flash = $(patsub %/,%,%(directory-path))
$(words n, text)	返回text中第n个单词	$(words 2, $(version_list))
$(sort list)	排序list参数并移出重复的项目	d-prefix = $(sort dbase db2 mysql)
$(shell command)	执行command命令	stdout := $(shell echo normal message)
$(wildcard pattern...)	wildcard函数的参数是一份模式列表，它会对列表中的每个模式进行扩展的动作。如果找不到相符的文件，返回空字符串	source := $(wildcard *.c *.h)
$(suffix name...)	返回参数中每个单词的后缀	same-suffix = $(filter 1 $(words $(sort $(suffix $1))))
$(basename name...)	返回文件名称中不含后缀的部分	$(basename $1)

有一个 make 的环境变量叫“MAKECMDGOALS”，这个变量中会存放你所指定的终极目标的列表，如果在命令行上，你没有指定目标，那么，这个变量是空值。



<<初级篇>>
上篇文章介绍了makefile的编写方法，相信大家有所收获。本文继续深入makefile，看看还有哪些高级用法可以大大提升我们的工作效率。本文是接着上篇博文——如何自己编写Makefile的，因此如果没有看过上篇文章的，建议先阅读一遍，以便更好地理解本文。

　　在规则中使用通配符

　　一个简单的例子

　　clean:
	         rm -f *.o

　　表示删除所有.o文件，这很好理解。

　　 print: *.c
	         lpr -p $?
			          touch print

　　表明print的生成依赖于所有.c文件，$?是一个自动化变量，以后会详细介绍。

 

　　文件搜寻

　　在一些大的工程中，有大量的源文件，我们通常的做法是把这许多的源文件分类，并存放在不同的目录中。所以，当make需要去找寻文件的依赖关系时，你可以在文件前加上路径，但最好的方法是把一个路径告诉make，让make在自动去找。

　　Makefile文件中的特殊变量“VPATH”就是完成这个功能的，如果没有指明这个变量，make只会在当前的目录中去找寻依赖文件和目标文件。如果定义了这个变量，那么，make就会在当当前目录找不到的情况下，到所指定的目录中去找寻文件了。

    VPATH = src:../headers

　　上面的的定义指定两个目录，“src”和“../headers”，make会按照这个顺序进行搜索。目录由“冒号”分隔。

　　另一个设置文件搜索路径的方法是使用make的“vpath”关键字（注意，它是全小写的）， 这不是变量，这是一个make的关键字，这和上面提到的那个VPATH变量很类似，但是它更为灵活。它可以指定不同的文件在不同的搜索目录中。这是一个很 灵活的功能。它的使用方法有三种：

    1、vpath <pattern> <directories>

    为符合模式<pattern>的文件指定搜索目录<directories>。

    2、vpath <pattern>

    清除符合模式<pattern>的文件的搜索目录。

    3、vpath

    清除所有已被设置好了的文件搜索目录。

　　vapth使用方法中的<pattern>需要包含“%”字符。“%”的意思是匹 配零或若干字符，例如，“%.h”表示所有以“.h”结尾的文件。<pattern>指定了要搜索的文件集， 而<directories>则指定了<pattern>的文件集的搜索的目录。例如：

    vpath %.h ../headers

　　该语句表示，要求make在“../headers”目录下搜索所有以“.h”结尾的文件。（如果某文件在当前目录没有找到的话）

　　我们可以连续地使用vpath语句，以指定不同搜索策略。如果连续的vpath语句中出现了相同的<pattern>，或是被重复了的<pattern>，那么，make会按照vpath语句的先后顺序来执行搜索。如：

    vpath %.c foo
	    vpath %.c blish
		    vpath %.c bar

　　其表示“.c”结尾的文件，先在“foo”目录，然后是“blish”，最后是“bar”目录。

    vpath %.c foo:bar
	    vpath %.c blish

　　而上面的语句则表示“.c”结尾的文件，先在“foo”目录，然后是“bar”目录，最后才是“blish”目录。

　　

　　伪目标

　　最早先的一个例子中，我们提到过一个“clean”的目标，这是一个“伪目标”，

 

    clean:
	            rm *.o temp

 

　　正像我们前面例子中的“clean”一样，即然我们生成了许多文件编译文件，我们也应该提供一个清除它们的“目标”以备完整地重编译而用。 （以“make clean”来使用该目标）

 

　　因为，我们并不生成“clean”这个文件。“伪目标”并不是一个文件，只是一个标签，由于 “伪目标”不是文件，所以make无法生成它的依赖关系和决定它是否要执行。我们只有通过显示地指明这个“目标”才能让其生效。当然，“伪目标”的取名不 能和文件名重名，不然其就失去了“伪目标”的意义了。

 

　　当然，为了避免和文件重名的这种情况，我们可以使用一个特殊的标记“.PHONY”来显示地指明一个目标是“伪目标”，向make说明，不管是否有这个文件，这个目标就是“伪目标”。

    .PHONY : clean

　　只要有这个声明，不管是否有“clean”文件，要运行“clean”这个目标，只有“make clean”这样。于是整个过程可以这样写：

     .PHONY: clean
	     clean:
		             rm *.o temp

　　伪目标一般没有依赖的文件。但是，我们也可以为伪目标指定所依赖的文件。伪目标同样可以作为 “默认目标”，只要将其放在第一个。一个示例就是，如果你的Makefile需要一口气生成若干个可执行文件，但你只想简单地敲一个make完事，并且， 所有的目标文件都写在一个Makefile中，那么你可以使用“伪目标”这个特性：

    all : prog1 prog2 prog3
	    .PHONY : all

    prog1 : prog1.o utils.o
	            cc -o prog1 prog1.o utils.o

    prog2 : prog2.o
	            cc -o prog2 prog2.o

    prog3 : prog3.o sort.o utils.o
	            cc -o prog3 prog3.o sort.o utils.o

　　我们知道，Makefile中的第一个目标会被作为其默认目标。我们声明了一个“all”的伪 目标，其依赖于其它三个目标。由于伪目标的特性是，总是被执行的，所以其依赖的那三个目标就总是不如“all”这个目标新。所以，其它三个目标的规则总是 会被决议。也就达到了我们一口气生成多个目标的目的。“.PHONY : all”声明了“all”这个目标为“伪目标”。

　　随便提一句，从上面的例子我们可以看出，目标也可以成为依赖。所以，伪目标同样也可成为依赖。看下面的例子：

    .PHONY: cleanall cleanobj cleandiff

    cleanall : cleanobj cleandiff
	            rm program

    cleanobj :
	            rm *.o

    cleandiff :
	            rm *.diff

　　“make cleanall”将清除所有要被清除的文件。“cleanobj”和“cleandiff”这两个伪目标有点像“子程序”的意思。我们可以输入“make cleanall”和“make cleanobj”和“make cleandiff”命令来达到清除不同种类文件的目的。

　　makefile中的自动化变量　

　　$@
　　代表法定中的目标文件名。万一目标是一个文档（Linux中，等闲称.a文件为文档），那么它代表这个文档的文件名。在多目标的形式法定中，它代表的是哪个引发法定被厉行的目标文件名。
　　$%
　　法定的目标文件是一个静态库文件时，代表静态库的一个成员名。例如，法定的目标是“foo.a(bar.o)”，那么，“$%”的值就为“bar.o”，“$@”的值为“foo.a”。万一目标不是函数库文件，其值为空。
　　$<
　　法定的第一个依靠文件名。万一是隐含法定，则它代表穿越目标指定的第一个依靠文件。
　　$?
　　所有比目标文件更新的依靠文件列表，空格瓜分。万一目标是静态库文件名，代表的是库成

 

员（.o文件）的更新情形。
　　$^
　　法定的所有依靠文件列表，利用空格分隔。万一目标是静态库文件名，它所代表的只能是所有库成员（.o文件）名。一个文件可重复的展目前目标的依靠中，变量“$^”只登记它的顺次引用情形。即便说变量“$^”会去掉重复的依靠文件。
　　$+
　　相仿“$^”，然而它保留了依靠文件中重复揭示的文件。重要用在过程链接时，库的穿插引用处所。





