- Bash Bourne Again Shell
- 使用环境：
  - `#!` 其后路径指定的程序负责解释脚本文件的shell程序
  - `#!/bin/bash`
- 运行
  - `chmod +x ./test.sh` 使脚本具有执行权限
  - `./test.sh` 执行脚本  ./ 当前目录查找
  - 作为解释器参数： `/bin/sh test.sh`

# shell语法

## 变量

定义变量时，变量名不加 `$` 

### 显式赋值

`your_name="fanchengdong"`

**变量名和 `=` 之间不能由空格**

### 语句赋值

```shell
for file in `ls /etc`

for file in $(ls /etc)
# 将/etc下目录的文件名循环出来
```

### 使用变量

变量名前加 `$`

```shell 
your_name='asdf'
echo $your_name
echo ${your_name} # ${} 中 {} 可选
```

`{}` 目的是帮助解释器识别变量边界

### 只读变量

`readonly` 定义只读变量，值不能被改变

```shell
my_url="www.baidu.com"
readonly my_url
```

### 删除变量

`unset` 删除变量，**不能删除只读变量**

### 变量类型

1. 局部变量：用户自定义变量
2. 环境变量：用于所有用户变量，用于用户进程之前，必须用export命令导出
3. shell变量：
4. 特定变量：运行时的一些相关信息

| $#   | 传递到脚本的参数个数                               |
| ---- | -------------------------------------------------- |
| $$   | 脚本运行时当前进程ID号，常用作临时变量后缀 root.$$ |
| $!   | 后台运行的&最后一个进程的ID号                      |
| $-   | 上一个命令的最后一个参数                           |
| $?   | 最后命令的退出状态，0：无错误                      |



## 字符串

`''  ""`

### 单引号

1. 单引号中的字符都会原样输出，变量无效
2. 不能出现单独一个单引号，只可成对出现——字符串拼接

### 双引号

1. 双引号中可以由变量
2. 双引号中可以出现转义字符

```shell
#!/tr='this is a sring\n'
name='fanchengdong'
echo $str
str2='this is second string'$name' \n'
echo -e $str2
str3="this is thired string \"$name\" \n"
echo -e $str3
```

### 字符串拼接

```shell
your_name="runoob"
# 使用双引号拼接
greeting="hello, "$your_name" !"
greeting_1="hello, ${your_name} !"
echo $greeting  $greeting_1
# 使用单引号拼接
greeting_2='hello, '$your_name' !'
greeting_3='hello, ${your_name} !'
echo $greeting_2  $greeting_3
```

### 获取字符串长度

`#str`

```shell
str='abcd'
echo ${#str}
```

`expr length "$str"`

### 提取子字符串

`${string:i:j}`

### 查找子字符串

查找字符 `i` 或 `o`

```shell
echo `expr index "$string" io`
```

## 数组

只支持一维数组，数组大小无限定

### 定义数组

数组名=(值1 值2 ... 值n)

```shell
array=(value0 value1 value2 value3)
array[0]=value0
array[1]=value1
```

### 读取数组

`${数组名[下标]}`

使用 `@` 获取数组中所有元素

```
echo ${array[@]}
```

数组长度：

```shell
${#array[@]}
${#array[n]}
```

## 运算符

### 算术运算符

```shell
#!/bin/bash

a=10
b=20

val=`expr $a + $b`
echo "a + b : $val"

val=`expr $a \* $b`

val=`expr $a / $b`

[ $a == $b]
[ $a != $b]
```



| 运算符 | 说明                                          | 举例                              |
| :----- | :-------------------------------------------- | :-------------------------------- |
| +      | 加法                                          | `expr $a + $b` 结果为 30。        |
| -      | 减法                                          | `expr $a - $b` 结果为 -10。       |
| *****  | **乘法**                                      | **`expr $a \* $b` 结果为  200。** |
| /      | 除法                                          | `expr $b / $a` 结果为 2。         |
| %      | 取余                                          | `expr $b % $a` 结果为 0。         |
| **=**  | **赋值**                                      | **a=$b 将把变量 b 的值赋给 a。**  |
| ==     | 相等。用于比较两个数字，相同则返回 true。     | [ $a == $b ] 返回 false。         |
| !=     | 不相等。用于比较两个数字，不相同则返回 true。 | [ $a != $b ] 返回 true。          |

### 关系运算符

| 运算符  | 说明                                                      | 举例                          |
| :------ | :-------------------------------------------------------- | :---------------------------- |
| -eq     | 检测两个数是否相等，相等返回 true。                       | [ $a -eq $b ] 返回 false。    |
| -ne     | 检测两个数是否不相等，不相等返回 true。                   | [ $a -ne $b ] 返回 true。     |
| -gt     | 检测左边的数是否大于右边的，如果是，则返回 true。         | [ $a -gt $b ] 返回 false。    |
| -lt     | 检测左边的数是否小于右边的，如果是，则返回 true。         | [ $a -lt $b ] 返回 true。     |
| -ge     | 检测左边的数是否大于等于右边的，如果是，则返回 true。     | [ $a -ge $b ] 返回 false。    |
| **-le** | **检测左边的数是否小于等于右边的，如果是，则返回 true。** | **[ $a -le $b ] 返回 true。** |

### 布尔运算符

| 运算符 | 说明                                                | 举例                                     |
| :----- | :-------------------------------------------------- | :--------------------------------------- |
| !      | 非运算，表达式为 true 则返回 false，否则返回 true。 | [ ! false ] 返回 true。                  |
| -o     | 或运算，有一个表达式为 true 则返回 true。           | [ $a -lt 20 -o $b -gt 100 ] 返回 true。  |
| -a     | 与运算，两个表达式都为 true 才返回 true。           | [ $a -lt 20 -a $b -gt 100 ] 返回 false。 |

### 逻辑运算符

| 运算符 | 说明       | 举例                                       |
| :----- | :--------- | :----------------------------------------- |
| &&     | 逻辑的 AND | [[ $a -lt 100 && $b -gt 100 ]] 返回 false  |
| \|\|   | 逻辑的 OR  | [[ $a -lt 100 \|\| $b -gt 100 ]] 返回 true |

### 字符串运算符

| 运算符 | 说明                                         | 举例                         |
| :----- | :------------------------------------------- | :--------------------------- |
| **=**  | **检测两个字符串是否相等，相等返回 true。**  | **[ $a = $b ] 返回 false。** |
| !=     | 检测两个字符串是否不相等，不相等返回 true。  | [ $a != $b ] 返回 true。     |
| **-z** | **检测字符串长度是否为0，为0返回 true。**    | **[ -z $a ] 返回 false**。   |
| -n     | 检测字符串长度是否不为 0，不为 0 返回 true。 | [ -n "$a" ] 返回 true。      |
| **$**  | **检测字符串是否为空，不为空返回 true。**    | **[ $a ] 返回 true。**       |



## 控制结构

### 选择结构

- `if`语句

  - ```shell
    if condition
    then
        command1 
        command2
        ...
        commandN 
    fi
    ```

  - ```shell
    if condition
    then
        command1 
        command2
        ...
        commandN
    else
        command
    fi
    ```

  - ```shell
    if condition1
    then
        command1
    elif condition2 
    then 
        command2
    else
        commandN
    fi
    ```

  - ```shell
    #!/bin/bash
    
    a=10
    b=20
    if [$a == $b]
    then
    	echo "a = b"
    elif [$a -gt $b]
    then
    	echo "a>b"
    elif [$a -lt $b]
    then
    	echo "a<b"
    else
    	echo "no"
    fi
    # 等价于
    if test $[a] -eq $[b]
    then
    	echo "="
    else
    	echo "!="
    fi
    ```

    

- `case`语句

  - ```shell
    case 值 in
    模式1)
        command1
        command2
        ...
        commandN
        ;;
    模式2）
        command1
        command2
        ...
        commandN
        ;;
    esac
    ```

    

### 循环结构

- `for`

  - ```shell
    for var in item1 item2 ... itemN
    do
        command1
        command2
        ...
        commandN
    done
    ```

    ```shell
    #!/bin/bash
    
    for loop in 1 2 3 4 5
    do
    	echo "the value is: $loop"
    done
    ```

    

- `util`循环条件在末尾，至少执行一次

- `while`条件在循环头部



## Shell重定向

| 命令            | 说明                                               |
| :-------------- | :------------------------------------------------- |
| command > file  | 将输出重定向到 file。                              |
| command < file  | 将输入重定向到 file。                              |
| command >> file | 将输出以追加的方式重定向到 file。                  |
| n > file        | 将文件描述符为 n 的文件重定向到 file。             |
| n >> file       | 将文件描述符为 n 的文件以追加的方式重定向到 file。 |
| n >& m          | 将输出文件 m 和 n 合并。                           |
| n <& m          | 将输入文件 m 和 n 合并。                           |
| << tag          | 将开始标记 tag 和结束标记 tag 之间的内容作为输入。 |

**文件描述符**

0：标准输入

1：标准输出

2：标准错误输出0





































