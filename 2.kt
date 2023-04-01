fun main() {
    fun getArr() = read.ints.drop(1).filter { it % 2 != 0 }
    fun List<Int>.bad() = count { it % 3 != 0 }
    val v1 = getArr()
    val v2 = getArr()
    val v3 = getArr()
    val all = v1.size.toLong() * v2.size * v3.size
    val bad = v1.bad().toLong() * v2.bad() * v3.bad()
    println(all - bad)
}

object read {
    val line get() = readln()
    val int get() = line.toInt()
    val ints get() = line.split(' ').map(String::toInt)
    val long get() = line.toLong()
    val longs get() = line.split(' ').map(String::toLong)
}