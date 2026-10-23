#import "@preview/muchpdf:0.1.2": muchpdf

#set page(
	paper: "a4",
	margin: (x: 0.8cm, y: 1.5cm)
)

#set text(
	size: 14pt,
)

#set par(first-line-indent: (
	amount: 2em,
	all: true
))

#set figure.caption(separator: [:])
#show figure.caption.where(kind: image): it => [
	#it.supplement #it.counter.display(it.numbering)#it.separator #it.body
]

#show raw.where(block: true): it => { set par(justify: false); grid(
  columns: (100%, 100%),
  column-gutter: -100%,
  block(width: 100%, inset: 1em, for i in it.text.split("\n") {
    linebreak()
  }),
  block(radius: 1em, fill: luma(246), width: 100%, inset: 1em, it),
)}
#show table.cell.where(y: 0): strong

#set page(numbering: none)
#align(center, block[
	#set text(size: 12pt)
	#set heading(outlined: false)
	= Министерство науки и вышего образования Российской Федерации
	= Федеральное государственное бюджетное образовательное учреждение высшего образования
	#set text(lang: "fr")
	= "Московский педагогический государственный университет"
])

#let count = 0
#while count < 10 {
	$ #linebreak() $
	count = count + 1
}

#align(center, block[
	#set text(size: 16pt)
	#set heading(outlined: false)
	= ОТЧЕТ ПО ЛАБОРАТОРНОЙ РАБОТЕ №6
])

#let count = 0
#while count < 10 {
	$ #linebreak() $
	count = count + 1
}

#align(center)[
	#table(
		columns: (8.85cm,) + (10.8cm,),
		stroke: none,

		table.cell(text(size: 13.4pt, "Выполнил студент группы ЗОМ34-ПВШ2616:"), align: right), table.cell(text(size: 14.4pt, "Золотухин Андрей Александрович"), align: left),
		table.cell(text(size: 14.4pt, "Ссылка на репозиторий:"), align: right), table.cell(text(size: 14.4pt, "https://github.com/CorgiPuppy/dslp-labs"), align: left),
		table.cell(text(size: 14.4pt, "Принял:"), align: right), table.cell(text(size: 14.4pt, "Жданов Сергей Александрович"), align: left),
		table.cell(text(size: 14.4pt, "Дата сдачи:"), align: right), table.cell(text(size: 14.4pt, "23.10.26"), align: left),
	)
]

#let count = 0
#while count < 5 {
	$ #linebreak() $
	count = count + 1
}

#align(center, block[
	#set text(size: 14.4pt)
	#set heading(outlined: false)
	= Москва
	= 2026
])

#pagebreak()

#align(center, block[
	#text(size: 20pt, weight: "bold")[СОДЕРЖАНИЕ]
])

#set heading(numbering: "1.1.1.")

#outline(title: none)

#pagebreak()

#align(center, block[
	= Задание 1
])
#align(center, block[
	== Ознакомление с примерами из лекции
])
#let codeblock = read("../Задание 1/src/check_prime.cpp")
#raw(codeblock, block: true, lang: "c++")
#let printblock = read("../Задание 1/assets/check_prime-1.txt")
#raw(printblock, block: true)
#let printblock = read("../Задание 1/assets/check_prime-2.txt")
#raw(printblock, block: true)
#figure(
	image("../Задание 1/assets/check_prime.png"),
	caption: [Авторская иллюстрация программы check_prime.cpp],
	supplement: [Рис.],
)
#let codeblock = read("../Задание 1/src/gen_primes.cpp")
#raw(codeblock, block: true, lang: "c++")
#let codeblock = read("../Задание 1/src/tab_primes1.cpp")
#raw(codeblock, block: true, lang: "c++")
#let printblock = read("../Задание 1/assets/tab_primes1.txt")
#raw(printblock, block: true)
#let codeblock = read("../Задание 1/src/tab_primes2.cpp")
#raw(codeblock, block: true, lang: "c++")
#let printblock = read("../Задание 1/assets/tab_primes2.txt")
#raw(printblock, block: true)

#pagebreak()

#align(center, block[
	= Задание 2
])
#let codeblock = read("../Задание 2/include/primes_utils.h")
#raw(codeblock, block: true, lang: "c++")
#let codeblock = read("../Задание 2/src/primes_utils.cpp")
#raw(codeblock, block: true, lang: "c++")
#let codeblock = read("../Задание 2/src/main.cpp")
#raw(codeblock, block: true, lang: "c++")
#let printblock = read("../Задание 2/assets/main-1.txt")
#raw(printblock, block: true)
#let printblock = read("../Задание 2/assets/main-2.txt")
#raw(printblock, block: true)
