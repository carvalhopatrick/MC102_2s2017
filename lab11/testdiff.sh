#!/bin/bash
# Script para rodar todos os testes e criar os arquivos de output
# para depois, compara-los com as saídas esperadas (diff)

cont=1
read -p "Qual o nome do arquivo do lab? " lab

for f in *in*
do 
	echo "Criando o arquivo 'out' para $f ..."
	./$lab <$f >$cont
	let cont=cont+1
done

cont=1

for r in *res*
do
	echo "Comparando arquivo $cont.svg com $r ..."
	diff $cont $r
	let cont=cont+1
done