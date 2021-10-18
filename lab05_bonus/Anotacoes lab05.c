[1ª fase]
	-Mesmas regras do lab05
	-Termina com o grifo voltando ao ponto de partida
	
[2ª fase]
	-Movimentos livres
	-Macho nao pode ultrapassar a qntd. de passos da femea
		(mas pode fazer menos passos)
		
	-Termina com um passo para trás maior q o passo anterior
		(deslocamento maior, distância contrária)

[3ª fase]
	-Macho deve fazer movimentos de mesma direção da femea
		(como na 1ª, pode ser rotacionado no espaço)
	-Macho pode agr também fazer passos menores ou iguais a da femea
	-Passos do macho devem seguir uma proporção igual durante a fase
	

/* Checar se pode haver compatibilidade reversa */
if (incompativel_flag == 2)
{
	/* Reverte a dança do macho */
	f = (passosM-1);
	for (i=0; i < passosM; i++)
	{
		aux = r_macho[f];
		r_macho[f] = r_macho[i];
		r_macho[i] = aux;
		
		aux = d_macho[f];
		d_macho[f] = d_macho[i];
		d_macho[i] = aux;
		
		f--;		
	}
	incompativel_flag = 10;
}