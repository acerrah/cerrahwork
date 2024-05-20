---
title: libft-tr
---

# Libft

## Bu döküman nasıl kullanılır?


**Lütfen!** Bunu okurken direk kodlara bakıp **geçmeyin**.  Kendiniz **kodlamayı deneyin** ardından koda bakıp farklılıkları görün. Öbür türlü öğrenmenize kep vurmuş olursunuz. Kafayı çalıştırın.
- - -

## Giriş

### Genel Talimatlar

- Proje C dilinde yazılmalı
- Norm'a uygun olmalı
- Fonksiyonlar belirtilmedikler sürece beklenmedik şekillerde çıkış yapmamalı (seg fault, bus error vb)
- Memory leak olmamalı
- Proje -Wall -Werror -Wextra flagleri ile derlenebilmeli
- Makefile minimum $(NAME), all, clean, fclean, re komutlarını barındırmalı
- Bonus için makefile'da ekstra bonus komudu olmalı
- 
### Libft nedir?
Libft 42'deki öğrencilik hayatınız boyunca (aksi söylenmedikçe) bol bol kullanacağınız bir C kütüphanesidir.

### Ne öğreneceksiniz?

- Nasıl kütüphane oluşturulur?
- Yeni fonksiyon ve kütüphaneler
- File descriptor nedir
- Structlar

- - -

## Zorunlu Kısım

### Header Dosyası
Header dosyası kütüphaneyi oluşturduktan sonra başka bir dosyada çağırırsanız compiler abimiz bunu alıp olduğu gibi (genel durumlar için geçerli) dosyada çağırdığınız yere yapıştıracak, bu sayede her seferinde tekrardan tanımlamanıza gerek kalmayacak. Bu nedenle header dosyası tüm fonksiyonlarınızı tanımalayacağınız yerdir. Ayrıca burda diğer kütüphaneleri tanımlayıp, bu kütüphaneyi çağırdığınız yerlerde çağrılmasını sağlayabilir, değişkenler ve makrolara tanımlayabilirsiniz.

``` c

//"ifndef" daha önce tanımlanmış bir değişken/kütüphane/fonksiyon'ların tekrardan tanımlanmamasını sağlar. ifndef olmadığı takdirde tekrar tanımlama durumunda kod hata verecektir. Tanımlarken '.' yerine syntax gereği '_' kullanılır
  

#ifndef LIBFT_H

# define LIBFT_H

//Proje boyunca gerekecek kütüphaneleriniz sadece aşağıdakiler

# include <stddef.h>

# include <unistd.h>

# include <stdlib.h>

  

//Projenin bonus kısmında kullanacağımız struct yapısı bunu şimdilik geçebilirsiniz ileride anlatıyorum
// BONUSU GEÇMEYİN ÖĞRENMENİZ GEREKEN ÖNEMLİ BİR KONU

typedef struct s_list

{

void*content;

struct s_list *next;

} t_list;

  
  

//yazacağınız fonksiyonları aşağıda tanımlıyoruz ki her projenize kütüphane çağırmak istediğnizde tek tek her dosyaya bunları yazmakla uğraşmayın. 

int ft_tolower(int c);

int ft_toupper(int c);

char *ft_strrchr(const char *s, int c);

char *ft_strmapi(char const *s, char (*f)(unsigned int, char));

size_t ft_strlen(const char *str);

size_t ft_strlcpy(char *dest, const char *src, size_t size);

size_t ft_strlcat(char *dest, const char *src, size_t size);

char *ft_strchr(const char *s, int c);

void *ft_memset(void *s, int c, size_t n);

void *ft_memcpy(void *dst, const void *src, size_t n);

char *ft_itoa(int n);

int ft_isprint(int c);

int ft_isdigit(int c);

int ft_isascii(int c);

int ft_isalpha(int c);

int ft_isalnum(int c);

void *ft_calloc(size_t count, size_t size);

void ft_bzero(void *s, size_t n);

int ft_strncmp(const char *s1, const char *s2, size_t n);

void *ft_memchr(const void *s, int c, size_t n);

char *ft_strnstr(const char *haystack, const char *needle, size_t len);

void *ft_memmove(void *dest, const void *src, size_t n);

int ft_memcmp(const void *s1, const void *s2, size_t n);

int ft_atoi(const char *s);

char *ft_strdup(const char *s1);

char *ft_strjoin(char const *s1, char const *s2);

char *ft_substr(char const *s, unsigned int start, size_t len);

char *ft_strtrim(char const *s1, char const *set);

char **ft_split(char const *s, char c);

void ft_putchar_fd(char c, int fd);

void ft_putstr_fd(char *s, int fd);

void ft_putendl_fd(char *s, int fd);

void ft_putnbr_fd(int n, int fd);

void ft_striteri(char *s, void (*f)(unsigned int, char*));

t_list *ft_lstnew(void *content);

void ft_lstadd_front(t_list **lst, t_list *new);

int ft_lstsize(t_list *lst);

t_list *ft_lstlast(t_list *lst);

void ft_lstadd_back(t_list **lst, t_list *new);

void ft_lstdelone(t_list *lst, void (*del)(void*));

void ft_lstclear(t_list **lst, void (*del)(void*));

void ft_lstiter(t_list *lst, void (*f)(void *));

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

  

#endif

//endif ifndef'i kapanışını temsil eder

  

````

  

### Makefile
Make build alma işlemlerini hızlandırmayı ve otomatize etmeyi kolaylaştırmayı sağlayan bir programdır. Makefile adlı dosyaların içersinden okudukları komutları çalıştırır. Bu projede sadece kütüphanemizi oluşturmak için kullanıyoruz.

Aşağıdaki syntax ile makefile içersinde oluşturduğumuz komutları çalıştıracağız  

make [TARGET ...]

  
Tabi ki bunu yapabilmek için öncelikle bir Makefile oluşturmalısınız. Bu proje için oluşturabileceğinizi en basit Makefile için input , output dosyalarınız, compiler ismi ve archive komutu yeterli olacaktır. Anlamadığınız yerleri araştırarak devam etmenizi şiddetle tavsiye ediyorum.

``` make

SRCS = ft_isalpha.c \

ft_isdigit.c \

ft_isalnum.c \

ft_isascii.c \

ft_isprint.c\

ft_strlen.c \

ft_bzero.c \

ft_memset.c \

ft_memcpy.c \

ft_calloc.c \

ft_strmapi.c \

ft_toupper.c \

ft_tolower.c \

ft_itoa.c \

ft_strchr.c \

ft_strrchr.c \

ft_strlcpy.c \

ft_strlcat.c \

ft_strncmp.c \

ft_memchr.c \

ft_memmove.c \

ft_memcmp.c \

ft_strnstr.c \

ft_atoi.c \

ft_strdup.c \

ft_strjoin.c \

ft_substr.c \

ft_strtrim.c \

ft_split.c \

ft_putchar_fd.c \

ft_putstr_fd.c \

ft_putendl_fd.c \

ft_putnbr_fd.c \

ft_striteri.c

  

MAIN = main.c

OBJS = ${SRCS:.c=.o}

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

RM = rm -rf

LIBC = ar rc

  

all: ${NAME}

  

${NAME}: ${OBJS}

${LIBC} ${NAME} ${OBJS}

  

clean:

${RM} ${OBJS} ${BOBJS}

  

fclean: clean

${RM} ${NAME}

  

re: fclean all

````

  

### Part 1 - Libc Fonksiyonları

**Not:** 42'de norm gereği tüm fonksiyonlarınızın 'ft_' prefixi ile başlaması zorunlu.

- #### isalpha

isalpha girilen argümanın  ascii'ye göre alfabetik olup olmadığın kontrol eder. True ya da False temsilen 1 ve 0 döner. 

``` c

#include "libft.h"

  

int ft_isalpha(int c)

  

{

return ((c >= 97 && c <= 122) || (c >= 65 && c <= 90));

}

````

- #### isdigit

isdigit girilen argümanın ascii'ye göre numerik olup olmadığın kontrol eder. True ya da False temsilen 1 ve 0 döner. 


``` c

#include "libft.h"

  

int ft_isdigit(int c)

  

{

return (c >=48 && c <= 57);

}

````

- #### isalnum

isalnum  girilen argümanın ascii'ye göre alfabetik ya da numerik olup olmadığın kontrol eder. True ya da False temsilen 1 ve 0 döner. 

``` c

#include "libft.h"

  

int ft_isalnum(int c)

{

return (ft_isalpha() || ft_isdigit());

}

````

- #### isascii

Ascii karakterleri 7 bitlik pozitif değerlerdir. isascii girilen argümanın ascii olup olmadığın kontrol eder.True ya da False temsilen 1 ve 0 döner. 

``` c

#include "libft.h"

  

int ft_isalnum(int c)

{

return ((c >= 0 || c <= 127);

}

````

- #### isprint

Ascii tablosuna göre 0 ve 31 (dahil) arasındaki değerler yazdırılamayan karakterler. isprint karakterlerin yazdırılabilir olup olmadığını kontrol eder. True ya da False temsilen 1 ve 0 döner. 

``` c

#include "libft.h"

  

int ft_isprint(int c)

{

return (c >= 32 && c <= 126);

}

````

- #### strlen

Strlen constant bir string değerini alır ve uzunluğunu geri döner. Argüman tipi const char pointer'dır ve return tipi size_t'dir.
  

**Not:**

- **"const"** kendisinden önce gelen değerin değitirilemez olduğunu gösterir

- "char const c;" char'dan sonra geldiği için c değer değiştirilemeyen bir karakterdir

- "char * const c;" Pointer'ın adresi değiştirilemez demektir.

- "char const * c;" Pointer'ın gösterdiği adresteki değer değiştirlemez bir değerdir. Char'dan sonra geldi.

- "char const * const c;" Hem pointer'ın gösterdiği adres hem de adresteki değer değiştirilemezdir.
  
Peki "size_t" nedir? Size_t bir değişkenin, pointerın, nesnenin (C'de nesne (object) yok ama C++'da da aynı olduğu için belirttim) boyutunu belirtmek için kullanılan bir değer tipidir. Değişkenlerin alabileceği değer boyutu sistemden sisteme değişiklik gösterdiği için size_t'nin boyutu da farklıdır ancak her zaman unsigned (yani pozitif) değerdir, malum memory'de negatif yer kaplayamazsınız.

- #### memset

Memset 3 argüman alır: pointer, koyulacak karakter, kaç adet koyulacağı. Verilen adresten itibaren belirtilen sayıda karakteri koyulmak istenen karakter ile değiştirir. Ve adresi döndürür.
  

Örnekteki şekilde kullanılırsa:

````c

char a[] = "hello world";

ft_memset(a, 'x', 5);

````

A array'i "xxxxx world" olacaktır.
  

``` c

#include "libft.h"

  

void *ft_memset(void *s, int c, size_t n)

{

size_t i;

  

i = 0;

while (i < n)

((unsigned char *)s)[i++] = c;

return (s);

}

````

- #### bzero

Bzero aynı memset gibi ama karakter almaz adresten itibaren belirtilen sayıda karakteri 0 yapar.

``` c

#include "libft.h"

  

void ft_bzero(void *s, size_t n)

{

size_t i;

  

i = 0;

while (i < n)

((unsigned char *)s)[i++] = 0;

}

````

- #### memcpy

Memcpy bir adresten diğerine n adet byte (char bir byte varsayıyoruz) kopyalar. Verilen adreslere ulaşımı var mı diye kontrol eder yoksa NULL döndürür. kopyalıcağı adreste ayrılan memory'nin dışına çıkıp çıkmadığını kontrol etmez bu nedenle taşmalara sebep olabilir. Sonuç olarak kopyaladığı adresi döndürür.

``` c

#include "libft.h"

  

void *ft_memcpy(void *dst, const void *src, size_t n)

{

size_t i;

  

if (!dst && !src)

return (NULL);

i = 0;

while (i < n)

{

*(char *)(dst + i) = *(char *)(src + i);

i++;

}

return (dst);

}

````

- #### memmove

Memmove memcopy ile neredeyse aynı çalışır ancak üst üste gelen değerleri de işleyebilir. Örneğin:

```c

char xd[] = "42 is awesome";

//memcpy karakter karakter kopyalama işlemi yaptığından bir önceki kopyalanan karakteri kopyalamaya devam edicektir.

memcpy(&xd[1], &xd[2], 3);

//42 is awesome -> 422is awesome

//422is awesome -> 4222s awesome

//4222s awesome -> 42222 awesome
```

Memmove ise kopyalama yapılacak adresleri kontrol ederek kopyalamayı baştan ya da sondan yapar.

``` c

#include "libft.h"

  

void *ft_memmove(void *dest, const void *src, size_t n)

{

size_t i;

  

if (!src && !dest)

return (0);

if (((size_t)dest - (size_t)src < n) && dest > src)

{

i = n - 1;

while (i < n)

{

*(char *)(dest + i) = *(char *)(src + i);

i--;

}

}

else

{

i = 0;

while (i < n)

{

*(char *)(dest + i) = *(char *)(src + i);

i++;

}

}

return (dest);

}

````

- #### strlcpy

Strlcpy memcpy gibi çalışır ama NULL gördüğü zaman durur.

``` c

#include "libft.h"

  

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)

{

size_t i;

  

i = 0;

if (dstsize)

{

while (i < (dstsize - 1) && *(src + i))

{

*(dst + i) = *(src + i);

i++;

}

*(dst + i) = '\0';

}

return (ft_strlen(src));

}

````

- #### strlcat

Strlcat bir stringi (char * 'lara string diye hitap edicem terimsel olarak doğru olmasa da üşeniyorum.) diğer stringin sonuna ekler. Kaç karakter ekleyeceğinizi belirtebilirisiniz. Oluşan string'in uzunluğunu döner.

``` c

#include "libft.h"

  

size_t ft_strlcat(char *dest, const char *src, size_t size)

{

size_t i;

  

if (!dest && !size)

return (0);

i = ft_strlen(dest);

if (i >= size)

return (ft_strlen(src) + size);

ft_strlcpy((dest + i), src, size - i);

return (i + ft_strlen(src));

}

````

- #### toupper

Toupper girilen argümandaki karakter ascii'de küçük harfse aynı karakterin büyük halinin ascii değerini döndürür.

``` c

##include "libft.h"

  

int ft_toupper(int c)

{

if ((unsigned char)c < 123 && (unsigned char)c >= 97)

{

c -= 32;

}

return ((unsigned char)c);

}

````

- #### tolower
Toupper'ın tam tersi.

``` c

#include "libft.h"

  

int ft_tolower(int c)

{

if ((unsigned char)c <= 90 && (unsigned char)c >= 65)

{

c += 32;

}

return ((unsigned char)c);

}

````

- #### strchr
String içersinde aranılmak istenen karakterin ilk görüldüğü adresi döndürür.

``` c

#include "libft.h"

  

char *ft_strchr(const char *s, int c)

{

int i;

  

i = 0;

if (!s && *s != 0)

return (0);

while (s[i] != 0)

{

if (s[i] == (char)c)

{

return ((char *)(s + i));

}

i++;

}

if ((char)c == s[i])

return ((char *)(s + i));

return (0);

}

````

- #### strrchr

strchr gibi çalışır ama adı üstünde str 'reverse' chr. Sondan başlayarak karakterin ilk bulunduğu adresi döndürür.

``` c

#include "libft.h"

  

char *ft_strrchr(const char *s, int c)

{

int i;

  

i = ft_strlen(s);

if (!s && *s != 0)

return (0);

while (i >= 0)

{

if (s[i] == (char)c)

{

return ((char *)(s + i));

}

i--;

}

if ((char)c == s[i])

return ((char *)(s + i));

return (0);

}

````

- #### strncmp

Strncmp iki stringi karşılaştırır ve ilk farklı karakterlerin farkını döndürür. Kaç karakter karşılaştırılacak belirtilmelidir. 

```

Her zaman string1'den string2'yi çıkarır ve döndürür.

```

``` c

#include "libft.h"

  

int ft_strncmp(const char *s1, const char *s2, size_t n)

{

size_t i;

  

i = 0;

while ((s1[i] != 0 || s2[i] != 0) && i < n)

{

if (s1[i] != s2[i])

return ((unsigned char)s1[i] - (unsigned char)s2[i]);

i++;

}

return (0);

}

````

- #### memchr

Memchr verilen adresteki istenen değerin baştan itibaren belirtilen sayıdaki karakterlerin arasından ilk görüldüğü yerdeki adresi döndürür.

``` c

#include "libft.h"

  

void *ft_memchr(const void *s, int c, size_t n)

{

size_t i;

  

i = 0;

while (i < n)

{

if (*(unsigned char *)(s + i) == (unsigned char)c)

return ((void *)(s + i));

i++;

}

return (NULL);

}

````

- #### memcmp

Strncmp'un aynısı ancak char pointer yerine void pointer alır.

``` c

#include "libft.h"

  

int ft_memcmp(const void *s1, const void *s2, size_t n)

{

size_t i;

  

i = 0;

while (i < n)

{

if (*(unsigned char *)(s1 + i) != *(unsigned char *)(s2 + i))

return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));

i++;

}

return (0);

}

````

- #### strnstr
İki adet string alır aldığı ikinci stringin, ilk stringin belirtilen boyutunun içersinde bulunup bulunmadığına bakar. String içersindeki ilk bulunduğu noktadaki adresi döner. Eğer bulunmuyorsa ikinci stringin adresini döner.

``` c

#include "libft.h"

  

char *ft_strnstr(const char *haystack, const char *needle, size_t len)

{

size_t i;

size_t n;

size_t flag;

size_t needle_len;

  

needle_len = ft_strlen(needle);

i = 0;

if (!needle_len)

return ((char *)(haystack));

else if (len == 0 || !haystack[0])

return (0);

while (i < len)

{

n = i;

flag = 0;

while ((*(needle + flag) == *(haystack + n)) && *(needle + flag) != '\0'

&& n++ < len)

flag++;

if (flag == needle_len)

return ((char *)(haystack + i));

i++;

}

return (0);

}

````

- #### atoi

Atoi string halindeki bir sayıyı alıp integer'a çevirip döndürür. Bunun için karakter karakter kontrol yapar sayı olmayan bir karakter gördüğünde durur. Sayının başında whitespace ve whitespacelerin ardından + ya da - bulunabilir.

``` c

#include "libft.h"

  

int ft_atoi(const char *s)

{

int i;

long back;

int np;

  

back = 0;

np = 1;

i = 0;

while ((s[i] <= 13 && s[i] >= 9) || s[i] == 32)

i++;

if (s[i] == 43 || s[i] == 45)

{

if (s[i] == 45)

np *= -1;

i++;

}

while (s[i] >= 48 && s[i] <= 57)

{

back = back * 10 + (s[i] - 48) * np;

if (back > 2147483647)

return (-1);

if (back < -2147483648)

return (0);

i++;

}

return ((int)back);

}

````

- #### calloc

Calloc iki argüman alır. İlk argüman çarpı ikinci argüman kadar void pointer'a yer açıp hepsini 0 ile doldurup, oluşturduğu pointer'ı döndürür.

``` c

#include "libft.h"

  

void *ft_calloc(size_t count, size_t size)

{

void *rtn;

size_t req;

  

req = count * size;

rtn = malloc(req);

if (!rtn)

return (0);

ft_memset(rtn, 0, req);

return (rtn);

}

````

- #### strdup

Strdup bir string alır ve onu kopyalayıp kopyaladığı stringin adresini döndürür.

``` c

#include "libft.h"

  

char *ft_strdup(const char *s1)

{

char *rtn;

size_t len;

  

len = ft_strlen(s1) + 1;

rtn = ft_calloc(len, sizeof(char));

if (!rtn)

return (0);

ft_strlcpy(rtn, s1, len);

return (rtn);

}

````

  

### Part 2 - Additional Functions

  

- #### substr
Verilen stringin istenilen değer aralığındaki karakterleri kopyalayıp yeni bir string'e adres döndürür.

``` c

#include "libft.h"

  

char *ft_substr(char const *s, unsigned int start, size_t len)

{

char *rtn;

size_t i;

  

if (!s)

return (0);

if (ft_strlen(s) < start)

return (ft_strdup(""));

if (len > ft_strlen(s) - start)

len = ft_strlen(s) - start;

i = 0;

rtn = ft_calloc(len + 1, sizeof(char));

if (!rtn)

return (NULL);

rtn[len] = 0;

while (i < len)

rtn[i++] = s[start++];

return (rtn);

}

````

- #### strjoin

İki stringi birbirine yapıştırıp yeni bir string oluşturur. Oluşan stringi döndürür.

``` c

#include "libft.h"

  

char *ft_strjoin(char const *s1, char const *s2)

{

char *back;

size_t total_len;

  

if (!s1 || !s2)

return (0);

total_len = (ft_strlen(s1) + ft_strlen(s2)) + 1;

back = malloc(total_len * sizeof(char));

if (!back)

return (0);

ft_strlcpy(back, s1, ft_strlen(s1) + 1);

ft_strlcat(back, s2, total_len);

return (back);

}

````

- #### strtrim
Stringin başından ve sonundan istenilen karakterleri siler. 

``` c

#include "libft.h"

int	check(char a, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (a == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;
	char	*rtn;

	i = 0;
	if (!s1)
		return (NULL);
	len = ft_strlen(s1) - 1;
	while (check(s1[i], set))
		i++;
	while (check(s1[len], set))
		len--;
	rtn = ft_substr(s1, i, len - i + 1);
	if (!rtn)
		return (NULL);
	return (rtn);
}

````

- #### split

Allocates and returns an array of strings obtained by splitting 's' using the character 'c' as a delimiter. The array must end with a NULL pointer.

``` c

#include "libft.h"

  

size_t ft_word_count(char const *s, char c)

{

size_t i;

size_t rtn;

  

i = 0;

rtn = 0;

while (s[i])

{

if (s[i] == c && s[i + 1] != c && s[i + 1] != 0)

rtn++;

i++;

}

if (s[0] != c)

rtn++;

return (rtn);

}

  

char **protect(void)

{

char **rtn;

  

rtn = ft_calloc(1, sizeof(char *));

rtn[0] = NULL;

return (rtn);

}

  

char **ft_split(char const *s, char c)

{

char **rtn;

size_t word_count;

size_t i;

size_t j;

size_t flag;

  

i = 0;

j = 0;

if (!s || s[0] == 0)

return (protect());

word_count = ft_word_count(s, c);

rtn = ft_calloc(word_count + 1, sizeof(char *));

if (!rtn)

return (NULL);

while (i < word_count)

{

while (s[j] == c)

j++;

flag = j;

while (s[j] != c && s[j])

j++;

rtn[i++] = ft_substr(s, flag, j - flag);

}

rtn[i] = NULL;

return (rtn);

}

````

- #### itoa

Allocates and returns a string representing the integer recevied as an argument. Negative numbers must be handled.

``` c

#include "libft.h"

  

int arlen(int n)

{

long a;

int i;

  

i = 0;

a = n;

if (a == 0)

return (1);

if (a < 0)

{

a *= -1;

i++;

}

while (a > 0)

{

a /= 10;

i++;

}

return (i);

}

  

void inarr(char *back, int a, int backlen)

{

long n;

  

n = a;

if (n < 0)

{

back[0] = '-';

n *= -1;

}

if (n >= 10)

{

inarr(back, n / 10, backlen - 1);

inarr(back, n % 10, backlen);

}

if (n < 10)

back[backlen] = n + 48;

}

  

char *ft_itoa(int n)

{

int backlen;

char *back;

  

backlen = arlen(n);

back = malloc((sizeof(char) * backlen) + 1);

if (!back)

return (0);

inarr(back, n, backlen - 1);

back[backlen] = '\0';

return (back);

}

````

- #### strmapi

Applies the function 'f' to each character of the string 's', and passing its index as first argument to create a new string resulting from successive applications of 'f'.

``` c

#include "libft.h"

  

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))

{

size_t i;

size_t len;

char *rtn;

  

if (!s)

return (0);

i = 0;

len = ft_strlen(s);

rtn = (char *)malloc(len * sizeof(char) + 1);

if (!rtn)

return (0);

while (i < len)

{

rtn[i] = (*f)(i, s[i]);

i++;

}

rtn[i] = '\0';

return (rtn);

}

````

- #### striteri

Applies the function ’f’ on each character of the string passed as argument, passing its index as first argument. Each character is passed by address to ’f’ to be modified if necessary.

``` c

#include "libft.h"

  

void ft_striteri(char *s, void (*f)(unsigned int, char *))

{

size_t i;

  

if (!s)

return ;

i = 0;

while (s[i])

{

(*f)(i, &s[i]);

i++;

}

}

````

- #### putchar_fd

Outputs the character ’c’ to the given file descriptor.

What is a file descriptor? File descriptor is a unsigned integer used by a process to identif an open file. In C, 0 is standard input, 1 is standard output, 2 is standard error. Every new file descriptor that is opened will take the next number that is free. For an example:

~~~c

unsigned int fd;

fd = open(xd.txt, O_RDWR);

//xd.txt is assigned into 3 so fd = 3

printf("%d", fd);

//this will print 3

~~~

Write functions first parameter is always file descriptor. write(1,*,*); means it will write a output to terminal because 1 is standard output by default.

~~~c

write(1,"xd",2);

//first function will write xd on the terminal

write(fd,"xd",42);

//second one will write xd into the xd.txt file

~~~

  

```c

#include "libft.h"

  

void ft_putchar_fd(char c, int fd)

{

write(fd, &c, 1);

}

````

- #### putstr_fd

Outputs the string ’s’ to the given file descriptor.

``` c

#include "libft.h"

  

void ft_putstr_fd(char *s, int fd)

{

size_t i;

  

i = 0;

if (!s)

return ;

while (s[i])

{

ft_putchar_fd(s[i], fd);

i++;

}

}

````

- #### putendl_fd

Outputs the string ’s’ to the given file descriptor followed by a newline.

``` c

void ft_putendl_fd(char *s, int fd)

{

ft_putstr_fd(s, fd);

ft_putchar_fd('\n', fd);

}

````

- #### putnbr_fd

Outputs the integer ’n’ to the given file descriptor.

``` c

#include "libft.h"

  

void ft_putnbr_fd(int n, int fd)

{

if (n == -2147483648)

{

ft_putchar_fd('-', fd);

ft_putchar_fd('2', fd);

ft_putnbr_fd(147483648, fd);

}

else if (n < 0)

{

ft_putchar_fd('-', fd);

n = n * (-1);

ft_putnbr_fd(n, fd);

}

else if (n > 9)

{

ft_putnbr_fd(n / 10, fd);

ft_putchar_fd(n % 10 + '0', fd);

}

else if (n < 10)

{

ft_putchar_fd(n + '0', fd);

}

}

````

- - -

## Bonus Part

  

What is a struct? A struct is a collection of variables (can be different types) under a single name.

  

First of all lets look at the syntax of a struct:

~~~c

struct structureName {

dataType member1;

dataType member2;

...

};

  

//For an example

struct 42Student {

char *name;

int cardno;

int intralevel;

char *intraid;

};

~~~

When a truct type is declared, no storage or memory is allocated. To allacote memory of a given structure type and work with it, we need to create variables.

  

~~~c

struct 42Student person1;

~~~

person1 is a struct 42Student variable.

  

#### Access Members of a Structure:

There are two types of operators used for accessing members of a structure.

1. `.` -Member operator

2. `->` -Structure pointer operator

  

For an example you want to access person1's intraid. Here's how you can do it.

```c

person1.intraid

```

#### Typedef

We use `typedef` keyword to create an alias for data types.

  

For example:

```c

typedef struct 42Student {

char *name;

int cardno;

int intralevel;

char *intraid;

} std;

  

int main() {

//we can just use std instead of struct 42Student

std studen1;

}

```

#### Linked List

  

Because we can add any type of variable in a struct we can also add pointer to another struct. We can link structs to eachother. For example:

  

~~~c

typedef struct 42Student {

char *intraid;

std *nextstudent;

} std;

  

int main() {

//we can just use std instead of struct 42Student

std *student1;

std *student2;

//if the variable is a struct pointer we use '->' instead of '.'

ft_strlcpy(student1->intraid, "acerrah", 7);

ft_strlcpy(student2->intraid, "hozdemir", 8);

student1->nextstudent = student2;

student2->nextstudent = NULL;

// by making these structs we made a link list

// student1--------------->student2

// -student1.intraid -student2.intraid

// we can go same way with the arrow but we can't come back because we will lost the address of studen1 the moment we change as student1 = student1->next; so instead we generally make a temporary variable to hold next values

}

~~~

Struct members are stored in the order they are declared.

If necessary, padding is added betwen struct members to ensure that the latter one uses the correct alignment.

Each primitive type T requires an alignmet of sizeof(T) bytes.

  

For example:

~~~c

struct ST

{

char ch1; // 1 + 1

short s; // 2

char ch2; // 1 + 3

long long ll; // 8

int i; // 4 + 4

};

//24 bytes in total with padding

struct ST

{

long long ll; // 8

int i; // 4

short s; // 2

char ch1; // 1

char ch2; // 1

} ST;

// 16 bytes in total without padding

~~~

  

- #### lst_new

Lst_new is a function that creates a new struct with its content as the parameter. Then it returns the new struct pointer.

``` c

#include "libft.h"

  

t_list *ft_lstnew(void *content)

{

t_list *node;

  

node = malloc(sizeof(t_list));

if (!node)

return (0);

node->content = content;

node->next = NULL;

return (node);

}

````

- #### lstadd_front

lstadd_front adds a new struct to the front of a linked list. New structs next will be the first element of the linked list.

``` c

#include "libft.h"

  

void ft_lstadd_front(t_list **lst, t_list *new)

{

new->next = (*lst);

(*lst) = new;

}

````

- #### lstsize

Lstsize counts how many elements in the linked list.

``` c

#include "libft.h"

  

int ft_lstsize(t_list *lst)

{

t_list *iter;

int i;

  

iter = lst;

i = 0;

while (iter != NULL)

{

i++;

iter = iter->next;

}

return (i);

}

````

- #### lstlast

Lstlast goes to the last element of the linked list and returns it.

``` c

#include "libft.h"

  

t_list *ft_lstlast(t_list *lst)

{

if (!lst)

return (NULL);

while (lst->next != NULL)

{

lst = lst->next;

}

return (lst);

}

````

- #### lstadd_back

Lstadd_back uses lstlast to go to last element of the linked list then adds a new struct to the end by changing the last element's next to new's address.

``` c

#include "libft.h"

  

void ft_lstadd_back(t_list **lst, t_list *new)

{

if (!new || !lst)

return ;

if (!*lst)

{

(*lst) = new;

}

else

{

(ft_lstlast(*lst))->next = new;

(ft_lstlast(*lst))->next = NULL;

}

}

````

- #### lstdelone

Lstdelone deletes an element from the linked list.

``` c

#include "libft.h"

  

void ft_lstdelone(t_list *lst, void (*del)(void*))

{

if (!lst || !del)

return ;

(*del)(lst->content);

free(lst);

}

````

- #### lstclear

Lstclear deletes all the elements of the list.

``` c

#include "libft.h"

  

void ft_lstclear(t_list **lst, void (*del)(void*))

{

t_list *cnext;

  

if (!lst || !del || !*lst)

return ;

cnext = (*lst);

while (cnext != (NULL))

{

cnext = (*lst)->next;

(*del)((*lst)->content);

free(*lst);

(*lst) = cnext;

}

}

````

- #### lstiter

Lstiter applies 'f' function to every content of the linked list's elements.

``` c

#include "libft.h"

  

void ft_lstiter(t_list *lst, void (*f)(void *))

{

if (!lst || !f)

return ;

while (lst != NULL)

{

(*f)(lst->content);

lst = lst->next;

}

}

````

- #### lstmap

Lstmap makes a new linked list with 'f' function applied to every element of the given linked list. If the f function doesn't work anywhere in the lstmap it frees all the new list and returns NULL.

``` c

#include "libft.h"

  

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))

{

t_list *nback;

void *data;

  

nback = NULL;

if (!lst || !f | !del)

return (nback);

while (lst != NULL)

{

data = (*f)(lst->content);

if (!data)

{

del(data);

ft_lstdelone(nback, del);

return (NULL);

}

ft_lstadd_back(&nback, ft_lstnew(data));

lst = lst->next;

}

return (nback);

}

````

- - -

## Sources

- https://github.com/acerrah/Libft/

- www.tutorialspoint.com

- - -

## Feedback

It has been a year or more if you read this later, so there might be mistakes or wrong knowledge. If you encounter any you can connect me through my [LinkedIn](https://www.linkedin.com/in/acerrah).