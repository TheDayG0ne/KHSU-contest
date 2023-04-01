
fun main() {
    fun getArr() = read.ints.drop(1).filter { it % 2 != 0 }
    fun List<Int>.bad() = count { it % 3 != 0 }
    val a = getArr()
    val b = getArr()
    val c = getArr()
    val all = a.size.toLong() * b.size * c.size
    val bad = a.bad().toLong() * b.bad() * c.bad()
    println(all - bad)
}


object read {
    val line get() = readln()

    val int get() = line.toInt()
    val ints get() = line.split(' ').map(String::toInt)

    val long get() = line.toLong()
    val longs get() = line.split(' ').map(String::toLong)
}
