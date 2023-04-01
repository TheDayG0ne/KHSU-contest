import kotlin.math.*

fun oversolve(test: Int) {
    val (m, d) = read.ints
    val (a, b) = read.ints
    val ans = when {
        a == b -> 0
        a == 0 || b == 0 -> m
        a %b == 0 || b %a == 0 -> min(m, d)
        else -> min(m, d) * 2
    }
    println(ans)
}

fun main() {
    val tn = 1//read.int
    repeat(tn) { test ->
        oversolve(test)
    }
}


//---reader---
object read {
    val line get() = readln()

    val int get() = line.toInt()
    val ints get() = line.split(' ').map(String::toInt)

    val long get() = line.toLong()
    val longs get() = line.split(' ').map(String::toLong)
}
