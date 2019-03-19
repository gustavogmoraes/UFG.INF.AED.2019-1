scanf("%i", &entrada);

	anoBase = entrada;
	
	if(anoBase >= ANOINICIAL) {
		printf("%i", ObtenhaProximoAnoPassagemCometa(anoBase, ANOINICIAL, '+'));
	} 
	else {
		printf("%i", ObtenhaProximoAnoPassagemCometa(anoBase, ANOINICIAL, '-'));
	}