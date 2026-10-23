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
	= ОТЧЕТ ПО ЛАБОРАТОРНОЙ РАБОТЕ №4
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
		table.cell(text(size: 14.4pt, "Принял:"), align: right), table.cell(text(size: 14.4pt, "Жданов Сергей Александрович"), align: left),
		table.cell(text(size: 14.4pt, "Дата сдачи:"), align: right), table.cell(text(size: 14.4pt, "10.10.26"), align: left),
		
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
	= Ознакомление с примерами из лекции
])
#let codeblock = read("../src/examples/DynamicArray.cpp")
#raw(codeblock, block:true, lang: "c++")
#let printblock = read("../src/examples/DynamicArray.txt")
#raw(printblock, block:true)

#let codeblock = read("../src/examples/Stack.cpp")
#raw(codeblock, block:true, lang: "c++")
#let printblock = read("../src/examples/Stack.txt")
#raw(printblock, block:true)

#pagebreak()

#align(center, block[
	= Основная задача
])
#let codeblock = read("../src/main.cpp")
#raw(codeblock, block:true, lang: "c++")
#let printblock = read("../src/main.txt")
#raw(printblock, block:true)
