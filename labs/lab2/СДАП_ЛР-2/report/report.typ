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
	= ОТЧЕТ ПО ЛАБОРАТОРНОЙ РАБОТЕ №2
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

		table.cell(text(size: 13.4pt, "Выполнил студент группы ЗОМ34-ПВШ261:"), align: right), table.cell(text(size: 14.4pt, "Золотухин Андрей Александрович"), align: left),
		table.cell(text(size: 14.4pt, "Принял:"), align: right), table.cell(text(size: 14.4pt, "Жданов Сергей Александрович"), align: left),
		table.cell(text(size: 14.4pt, "Дата сдачи:"), align: right), table.cell(text(size: 14.4pt, "25.09.26"), align: left),
		
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
	= Запуск примеров
])
#let codeblock = read("../src/examples/aray2D.cpp")
#raw(codeblock, block:true, lang: "c++")
#let printblock = read("../src/examples/aray2D.txt")
#raw(printblock, block:true)

#let codeblock = read("../src/examples/stru_example.cpp")
#raw(codeblock, block:true, lang: "c++")
#let printblock = read("../src/examples/stru_example.txt")
#raw(printblock, block:true)

#pagebreak()

#align(center, block[
	= Задача 1
])
#let codeblock = read("../src/task1/task1.cpp")
#raw(codeblock, block:true, lang: "c++")
#let printblock = read("../src/task1/task1.txt")
#raw(printblock, block:true)

#pagebreak()

#align(center, block[
	= Задача 2
])
#let codeblock = read("../src/task2/task2.cpp")
#raw(codeblock, block:true, lang: "c++")
#let printblock = read("../src/task2/task2.txt")
#raw(printblock, block:true)
