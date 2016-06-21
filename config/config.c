#include "config.h"

int startCount = 0;
int goalCount = 0;
int bumperCount = 0;
int jamabarCount = 0;
int bananaCount = 0;

void parseConfig(char * configpath)
{
	FILE * config = fopen(configpath,"r");
	char line[80];
	char ident[80];
	int index;
	char param1[80];
	char param2;
	char value[80];
	while(fgets(line,80,config)!=NULL)
	{
		sscanf(line," %s [ %i ] . %s . %c = %s ",ident,&index,param1,&param2,value);
		if(strcmp(ident,"start")==0)
		{
			if(strcmp(param1,"pos")==0)
			{
				float valuef = 0.0;
				sscanf(value,"%f",&valuef);
				if(param2=='x') starts[index].posx = valuef;
				else if(param2=='y') starts[index].posy = valuef;
				else if(param2=='z') starts[index].posz = valuef;
				if((index+1)>startCount) startCount = (index+1);
			}
			else if(strcmp(param1,"rot")==0)
			{
				float valuef = 0.0;
				sscanf(value,"%f",&valuef);
				if(param2=='x') starts[index].rotx = valuef;
				else if(param2=='y') starts[index].roty = valuef;
				else if(param2=='z') starts[index].rotz = valuef;
				if((index+1)>startCount) startCount = (index+1);
			}
		}
		else if(strcmp(ident,"goal")==0)
		{
			if(strcmp(param1,"pos")==0)
			{
				float valuef = 0.0;
				sscanf(value,"%f",&valuef);
				if(param2=='x') goals[index].posx = valuef;
				else if(param2=='y') goals[index].posy = valuef;
				else if(param2=='z') goals[index].posz = valuef;
				if((index+1)>goalCount) goalCount = (index+1);
			}
			else if(strcmp(param1,"rot")==0)
			{
				float valuef = 0.0;
				sscanf(value,"%f",&valuef);
				if(param2=='x') goals[index].rotx = valuef;
				else if(param2=='y') goals[index].roty = valuef;
				else if(param2=='z') goals[index].rotz = valuef;
				if((index+1)>goalCount) goalCount = (index+1);
			}
			else if(strcmp(param1,"type")==0)
			{
				char valuec = 'B';
				sscanf(value,"%c",&valuec);
				if(param2=='B') goals[index].type = 0;
				else if(param2=='G') goals[index].type = 1;
				else if(param2=='R') goals[index].type = 2;
				if((index+1)>goalCount) goalCount = (index+1);
			}
		}
		else if(strcmp(ident,"bumper")==0)
		{
			if(strcmp(param1,"pos")==0)
			{
				float valuef = 0.0;
				sscanf(value,"%f",&valuef);
				if(param2=='x') bumpers[index].posx = valuef;
				else if(param2=='y') bumpers[index].posy = valuef;
				else if(param2=='z') bumpers[index].posz = valuef;
				if((index+1)>bumperCount) bumperCount = (index+1);
			}
			else if(strcmp(param1,"rot")==0)
			{
				float valuef = 0.0;
				sscanf(value,"%f",&valuef);
				if(param2=='x') bumpers[index].rotx = valuef;
				else if(param2=='y') bumpers[index].roty = valuef;
				else if(param2=='z') bumpers[index].rotz = valuef;
				if((index+1)>bumperCount) bumperCount = (index+1);
			}
			else if(strcmp(param1,"scl")==0)
			{
				float valuef = 0.0;
				sscanf(value,"%f",&valuef);
				if(param2=='x') bumpers[index].sclx = valuef;
				else if(param2=='y') bumpers[index].scly = valuef;
				else if(param2=='z') bumpers[index].sclz = valuef;
				if((index+1)>bumperCount) bumperCount = (index+1);
			}
		}
		else if(strcmp(ident,"jamabar")==0)
		{
			if(strcmp(param1,"pos")==0)
			{
				float valuef = 0.0;
				sscanf(value,"%f",&valuef);
				if(param2=='x') jamabars[index].posx = valuef;
				else if(param2=='y') jamabars[index].posy = valuef;
				else if(param2=='z') jamabars[index].posz = valuef;
				if((index+1)>jamabarCount) jamabarCount = (index+1);
			}
			else if(strcmp(param1,"rot")==0)
			{
				float valuef = 0.0;
				sscanf(value,"%f",&valuef);
				if(param2=='x') jamabars[index].rotx = valuef;
				else if(param2=='y') jamabars[index].roty = valuef;
				else if(param2=='z') jamabars[index].rotz = valuef;
				if((index+1)>jamabarCount) jamabarCount = (index+1);
			}
			else if(strcmp(param1,"scl")==0)
			{
				float valuef = 0.0;
				sscanf(value,"%f",&valuef);
				if(param2=='x') jamabars[index].sclx = valuef;
				else if(param2=='y') jamabars[index].scly = valuef;
				else if(param2=='z') jamabars[index].sclz = valuef;
				if((index+1)>jamabarCount) jamabarCount = (index+1);
			}
		}
		else if(strcmp(ident,"banana")==0)
		{
			if(strcmp(param1,"pos")==0)
			{
				float valuef = 0.0;
				sscanf(value,"%f",&valuef);
				if(param2=='x') bananas[index].posx = valuef;
				else if(param2=='y') bananas[index].posy = valuef;
				else if(param2=='z') bananas[index].posz = valuef;
				if((index+1)>bananaCount) bananaCount = (index+1);
			}
			else if(strcmp(param1,"type")==0)
			{
				char valuec = 'N';
				sscanf(value,"%c",&valuec);
				if(param2=='N') bananas[index].type = 0;
				else if(param2=='B') bananas[index].type = 1;
				if((index+1)>bananaCount) bananaCount = (index+1);
			}
		}
	}
	fclose(config);
}
