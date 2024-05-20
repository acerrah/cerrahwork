This is some of the questions that I have been asked in job interviews and basically **past me** was nervous and fucked it up so I took better notes that explains these questions. It is in Turkish and shall be. For now...

## Sistem Programlama İş Görüşmesi Soruları

**Q: Thread ve Process arasındaki farklar nelerdir?**

A: Process bir programın çalıştırılabilir bir örneğidir. Thread ise bir process içinde çalışan bir iş parçacığıdır. Process'ler birbirlerinden bağımsızdır ve kendi adres alanlarına sahiptirler. Thread'ler ise aynı process içinde çalışır ve process'in adres alanını paylaşırlar. Thread'ler arasında veri paylaşımı daha kolaydır ve daha hızlıdır. Process'ler arasında veri paylaşımı ise daha zordur ve daha yavaştır. C'de thread oluşturmak için `pthread` kütüphanesi kullanılırken, process oluşturmak için `fork` sistem çağrısı kullanılır. Fork'lanan process aynı programın bir kopyasını oluştururken, thread'ler aynı programın aynı kopyasında çalışır.

**Q: Threadlerde race condition nedir? Nasıl önlenir?**

A: Race condition, birden fazla thread'in aynı anda aynı değişkeni okuyup yazması durumunda ortaya çıkan durumdur. Bu durumda thread'lerin sıraları ve zamanlamaları nedeniyle beklenmeyen sonuçlar ortaya çıkabilir. Önlemek için kritik bölge (critical section) kullanılabilir. Kritik bölge, aynı anda sadece bir thread'in erişebileceği bir bölgedir. Bu bölgeye giren diğer thread'ler bekler ve sırayla işlem yaparlar. Kritik bölgeye girmek için mutex, semaphore veya diğer senkronizasyon mekanizmaları kullanılabilir.

**Q: NAT nedir nasıl çalışır? IPv6'da NAT var mıdır?**

A: Network Address Translation yani NAT ağdaki IP adreslerini dönüştürmek için kullanılan bir tekniktir. NAT, özel IP adreslerini (örneğin 192.168.x.x) genel IP adresine dönüştürerek internete çıkış yapmayı sağlar. NAT, ağdaki cihazların genel IP adresini paylaşmasına olanak tanır ve ağdaki cihazların dış dünya ile iletişim kurmasını sağlar. IPv6'da NAT'a gerek kalmaz çünkü IPv6 adres alanı oldukça geniştir ve IP adresi kıtlığı sorunu yaşanmaz. Ancak bazı durumlarda IPv6'da da NAT kullanılabilir. Genellikle IPv4 ile IPv6 arasında geçişte kullanılır.

**Q: STUN TURN ICE nedir? Ne işe yarar?**

A: STUN (Session Traversal Utilities for NAT), NAT'ın arkasındaki IP adresini ve port numarasını tespit etmek için kullanılan bir protokoldür. TURN (Traversal Using Relays around NAT), NAT'ın arkasındaki cihazların birbirleriyle iletişim kurmasını sağlamak için kullanılan bir protokoldür. ICE (Interactive Connectivity Establishment), STUN ve TURN'ü bir araya getiren ve NAT'ın arkasındaki cihazların birbirleriyle iletişim kurmasını sağlayan bir protokoldür. Bu protokoller genellikle VoIP ve video konferans uygulamalarında kullanılır.

**Q: TTL nedir nasıl çalışır?**

A: TTL (Time To Live), IP paketlerinin ağda ne kadar süreyle kalacağını belirleyen bir değerdir. TTL değeri her yönlendirici (router) tarafından bir birim azaltılır. Eğer TTL değeri sıfıra düşerse paket atılır ve göndereni bilgilendirilir. TTL değeri kaç router üstünden geçtiğini(hop) belirler ve ağda dolaşan paketlerin sonsuz döngüde kalmasını engeller.

**Q: Veri yapılırını hiç duydun mu? Genel olarak ne işe yarar?**

A: Veri yapısı, verilerin depolanması ve düzenlenmesi için kullanılan yapıdır. Veri yapıları, verilerin etkili bir şekilde saklanması, erişilmesi ve işlenmesi için geliştirilmiş algoritmalar ve veri yapıları içerir. Genelde kullanılan belli başlı veri yapılar şunlardır: Array, Linked List, Stack, Queue, Tree, Graph, Hash Table, Heap, Set, Map. Kullanımlarından bahsetmek gerekirse array, verilerin sıralı bir şekilde depolanması ve erişilmesi için kullanılır. Linked List, verilerin dinamik olarak depolanması ve erişilmesi için kullanılır. Stack, verilerin LIFO (Last In First Out) mantığıyla depolanması ve erişilmesi için kullanılır. Queue, verilerin FIFO (First In First Out) mantığıyla depolanması ve erişilmesi için kullanılır. Tree, verilerin hiyerarşik bir şekilde depolanması ve erişilmesi için kullanılır. Graph, verilerin düğüm ve kenarlarla temsil edildiği bir yapıdır ve karmaşık ilişkileri modellemek için kullanılır. Hash Table, verilerin anahtar-değer çiftleri şeklinde depolanması ve erişilmesi için kullanılır. Erişmek için anahtar tekrardan hash fonksiyonundan geçirilir. Hash fonksiyonu tek yönlüdür, geri çevrilemez. Heap, verilerin öncelik sırasına göre depolanması ve erişilmesi için kullanılan özel bir tree yapısıdır. Set, benzersiz elemanların depolanması ve erişilmesi için kullanılır. Map, anahtar-değer çiftlerinin depolanması ve erişilmesi için kullanılır.

**Q: DNS nedir nasıl çalışır?**

A: DNS (Domain Name System), internet üzerindeki alan adlarını IP adreslerine çeviren bir sistemdir. DNS, alan adlarını IP adreslerine çevirirken DNS sunucularını kullanır. Bir alan adı çözümlenirken, önce yerel DNS sunucusuna, ardından kök DNS sunucusuna, ardından alan adı sunucusuna ve en sonunda hedef IP adresine gidilir. Her seferinde en üst DNS sunucusuna ulaşılmaz, kayıtlar yerel DNS sunucusunda önbelleğe alınır ve tekrar sorgulama yapmadan hızlı bir şekilde çözümlenir.

**Q: C dilinde Heap ve Stack memorynin farkı nedir?**

A: Heap dinamik olarak oluşturulan verilerin depolandığı bellek alanıdır. Pointer'lara açılan bellek alanları heap'te depolanır. Heap'te depolanan verilerin yaşam süresi programın çalışma süresiyle sınırlıdır ve program sonlandığında bellek alanı serbest bırakılır. Stack ise programın çalışma süresiyle sınırlı olan ve otomatik olarak oluşturulan verilerin depolandığı bellek alanıdır. Stack'te depolanan verilerin yaşam süresi, değişkenin tanımlandığı blok veya fonksiyonun çalışma süresiyle sınırlıdır. Stack'te depolanan veriler otomatik olarak serbest bırakılır ve bellek yönetimi işlemci tarafından yapılır. Pointerı free'ledikten sonra pointer aracılığı ile veriye ulaşılmaya çalışılırsa garbage value oluşur. Pointer'da memory allocation yapılmadan data atamaya çalışılırsa segmentation fault oluşur.

**Q: IP ve Ethernet Headerları neler içerir?**

A: Ethernet headerı'ında Dest Mac Adresi, Source Mac Adresi ve EtherType alanları bulunur. IP header'ında Source IP Adresi, Destination IP Adresi, Protocol, TTL, Header Checksum alanları bulunur. Protokol yollanıcak datanın hangi protokol ile yollanacağını belirtir. TTL(Time To Live) paketin ağda ne kadar süre kalacağını belirler. Header Checksum ise header'ın doğru bir şekilde olup olmadığını kontrol eder.

**Q: C ve C++ arasındaki farklar nelerdir?**

A: C++, class, obje, inheritance, polymorphism, encapsulation gibi object oriented programming özelliklerini destekler. C++'da standart libraryler daha fazladır, C'de ise sadece temel I/O, memory management ve string manipulation libraryleri bulunur. C++ dinamik memory allocation'ı destekler ve new, delete keywordleri ile kullanılır.

**Q: Class ve struct arasındaki fark nedir?**

A: C'deki class ve struct arasındaki fark ise C'de struct'lar sadece veri tutarlar, fonksiyonlar tanımlanamaz. Class'lar ise veri ve fonksiyonları bir arada tutarlar.Struct'lar default olarak public erişim belirleyicisine sahiptir. Class'lar ise private erişim belirleyicisine sahiptir.

**Q: Bir array içersinde 2. en büyük sayıya nasıl ulaşırsın?**

A: 2 farklı variable tanımlarım, biri en büyük sayıyı tutacak diğeri ise 2. en büyük sayıyı tutacak. Array'ı dolaşırken en büyük sayıyı bulurum ve 2. en büyük sayıyı güncellerim. O(n) complexity'e sahip bir algoritma olur.
