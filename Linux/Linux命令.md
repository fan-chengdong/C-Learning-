# grep命令 

在文件中查找文本

global regular expression print，全局正则表达式输出

## 语法

`grep [OPTIONS] PATTERN [FILE]`

- OPTIONS:零个或多个选项，包含控制其行为的选项
- PATTERN:搜索模式
- FILE:零个或多个文件名

## 搜索字符串（文本）

要显示/etc/passwd文件中包含字符串bash的所有行

```linux
grep bash /etc/passwd
```

## 反转匹配

`-v`选项

```linux
grep -v bash /etc/passwd
```

## 过滤命令的输出

通过 `grep`使用管道过滤命令的输出，并且只有与给定模式匹配的行才会打印在终端上

要找出哪些系统以用户www-data的身份在系统上运行，可以使用以下ps命令

```linux
ps -ef | grep www-data
```

可以链接多个管道

## 递归搜索

`-r` 选项 grep将搜索指定目录中的所有文件，并跳过递归遇到的符号连接（`-R`）

显示如何在/etc目录内的所有文件中搜索字符串linuxidc

## 显示行号

`-n` 

显示包含与模式匹配的字符串的行的行号

要显示/etc/services文件中的包含字符串bash并带有匹配行号的行

```linux
grep -n 10000 /etc/services
```

## count函数匹配

## 安静模式

`-q`

不在标准输出上显示任何内容，找到匹配项，以0退出

sell脚本

```shell
if grep -q PATTERN filename
then
	echo pattern found
else
	echo pattern not found
fi
```



# sed 命令

利用脚本处理文本文件

sed可依照脚本的指令处理、编辑文本文件

用于自动编辑一个或多个文件、简化对文件的反复操作、编写转换程序等

## 语法

`sed [-hnV][-e<script>][-f<script文件>][文本文件]`

- `-e<script>`或`--expression=<script>` 以选项中指定的script来处理输入的文本文件。
- -f<script文件>或--file=<script文件> 以选项中指定的script文件来处理输入的文本文件。
- -h或--help 显示帮助。
- -n或--quiet或--silent 仅显示script处理后的结果。
- -V或--version 显示版本信息。

动作：

- a：新增 
- c：取代，取代n1到n2之间的行
- d：删除
- i：插入  修改原文件内容
- p:打印  `sed -n p`
- s：取代

在testfile文件的第四行后添加一行，并将结果输出到标准输出

```linux
sed -e 4a\newLine testfile
```





# sort 命令

## 语法

```
sort [-bcdfimMnr][-o<输出文件>][-t<分隔字符>][+<起始栏位>-<结束栏位>][--help][--verison][文件]
```



- `-n` 按照数值大小排序
- `-u`去重
- `-o` 输出指定文件

`sort -n sort.txt`



# 文件管理命令

## find

`find path -option [-print] [-exec -ok command] {} \;`

将当前目录及其子目录下所有文件后缀为 **.c** 的文件列出来

```linux
find . -name "*.c"
```

- .当前目录
- *.c  后缀为 .c

## mv

`mv [option] source dest`

- **-b**: 当目标文件或目录存在时，在执行覆盖前，会为其创建一个备份。
- **-i**: 如果指定移动的源目录或文件与目标的目录或文件同名，则会先询问是否覆盖旧文件，输入 y 表示直接覆盖，输入 n 表示取消该操作。
- **-f**: 如果指定移动的源目录或文件与目标的目录或文件同名，不会询问，直接覆盖旧文件。
- **-n**: 不要覆盖任何已存在的文件或目录。
- **-u**：当源文件比目标文件新或者目标文件不存在时，才执行移动操作

## mkdir[rmdir]

`mkdir [-p] dirName`

- -p 目录不存在就创建一个

```linux
mkdir -p testDir/test
```



## rm

`rm [option] name...`

- -i 删除前逐一询问确认。
- -f 即使原档案属性设为唯读，亦直接删除，无需逐一确认。
- -r 将目录及以下之档案亦逐一删除。递归删除

## cp

`cp [options] source dest`

- -a：此选项通常在复制目录时使用，它保留链接、文件属性，并复制目录下的所有内容。其作用等于dpR参数组合。
- -d：复制时保留链接。这里所说的链接相当于Windows系统中的快捷方式。
- -f：覆盖已经存在的目标文件而不给出提示。
- -i：与-f选项相反，在覆盖目标文件之前给出提示，要求用户确认是否覆盖，回答"y"时目标文件将被覆盖。
- -p：除复制文件的内容外，还把修改时间和访问权限也复制到新文件中。
- -r：若给出的源文件是一个目录文件，此时将复制该目录下所有的子目录和文件。
- -l：不复制文件，只是生成链接文件。



## awk

https://www.runoob.com/linux/linux-comm-awk.html







## 进程检测

|      |      |      |      |
| ---- | ---- | ---- | ---- |
|      |      |      |      |
|      |      |      |      |
|      |      |      |      |
|      |      |      |      |





















