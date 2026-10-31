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
	= ОТЧЕТ ПО ЛАБОРАТОРНОЙ РАБОТЕ №8
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
		table.cell(text(size: 14.4pt, "Дата сдачи:"), align: right), table.cell(text(size: 14.4pt, "31.10.26"), align: left),
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
#let codeblock = read("../Задание 1/src/functor1.cpp")
#raw(codeblock, block: true, lang: "c++")
#let printblock = read("../Задание 1/assets/functor1.txt")
#raw(printblock, block: true)

#let codeblock = read("../Задание 1/src/functor2.cpp")
#raw(codeblock, block: true, lang: "c++")
#let printblock = read("../Задание 1/assets/functor2.txt")
#raw(printblock, block: true)
#let count = 0
#while count < 2 {
	#figure(
		image("../Задание 1/assets/functor1-"count".png"),
		caption: [Авторская иллюстрация программы functor1.cpp],
		supplement: [Рис.],
	)
	count += 1
}

#let codeblock = read("../Задание 1/src/prlambda1.cpp")
#raw(codeblock, block: true, lang: "c++")
#let printblock = read("../Задание 1/assets/prlambda1.txt")
#raw(printblock, block: true)
#let codeblock = read("../Задание 1/src/prlambda2.cpp")
#raw(codeblock, block: true, lang: "c++")
#let printblock = read("../Задание 1/assets/prlambda2.txt")
#raw(printblock, block: true)

#pagebreak()

#align(center, block[
	= Задание 2
])
#align(center, block[
	== Решение теста
])
#let data = read("../Задание 2/Задание2_ЗолотухинАндрей_ЗOМ34-ПВШ2616.pdf", encoding: none)
#figure(
	grid(
		columns: 2,
		muchpdf(data, pages: 0),
		muchpdf(data, pages: 1),
		muchpdf(data, pages: 2, width: 7cm),
	)
)

#pagebreak()

#align(center, block[
	= Задание 3
])
#let codeblock = read("../Задание 3/src/main.cpp")
#raw(codeblock, block: true, lang: "c++")
#let printblock = read("../Задание 3/assets/main.txt")
#raw(printblock, block: true)
#let printblock = read("../Задание 3/assets/main.txt")
#raw(printblock, block: true)
#let printblock = read("../Задание 3/assets/main.txt")
#raw(printblock, block: true)
