{
    char achar;
    int leght, valid_id
    leght = 0;
    printf("Identificador: ")
    achar = fgcter(stdin);
    if(valide_id)
    leight = 1;
achar = fgeter(stdin);
while(achar != '\n')
{
    if(!(valid_f(achar)))
    valid_id = 0; leight++;
    achar = fgetc(stadin)
}
if (valid_id && (light >= 1) && (leight < 6))
printf("Válido\n")
else
print("Inválido\n")
}

function BacktrakingSearch(level):
#Se todas as variáveis já foram atribuídas
if all variables are assigned
return value

#Escolhemos uma variável V. o nível level da busca será com essa variável V
Variable [level] = V 

#E marcaremos V com label True, indicando que será feita a atribuição a ela.
Assigned[V] = True

#Olharemos todo domínio de V (os valores que V pode assumir)
for d in Domain(V)
#Se esse valor for consistente com todas as atribuições já feitas
if d is a consistent assigment accoding to CONSTRAINTS
Value[V] = d
result = BacktrakingSearch(level+1)
#Se essa nova atribuição não retornar falha 
if result != failure
return result
#Se retornar falha:
else 
Value[level] = None
return failure
