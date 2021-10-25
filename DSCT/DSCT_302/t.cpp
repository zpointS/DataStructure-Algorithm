pNArray tempblock = NULL;    
unsigned int ** TempA, ** TempB;   
unsigned int ** TempEndBuff;    
NArray JobArray,JobPath;    
int dest,tag,i,j,k , m,n;    
MPI_Status status;    
double startwtime = 0.0, endwtime;   
 MPI_Datatype My_MPI_JobArr , My_MPI_JobLine;    
 /*MPI Initial*/   
MPI_Init(&argc,&argv);    
startwtime = MPI_Wtime();    
MPI_Comm_size(MPI_COMM_WORLD,&NumProcs);    
MPI_Comm_rank(MPI_COMM_WORLD,&MyID);    
MPI_Get_processor_name(processor_name,&namelen);   
 /*Wrong Processor numbers,exit*/    
if( !CheckProcessor(NumProcs) )    {
	         AppErrorExit(Err_APP_PROCS);    }    
MPI_Type_contiguous(Sides*Sides,MPI_UNSIGNED,&My_MPI_JobArr);    
MPI_Type_commit(&My_MPI_JobArr);   
MPI_Type_contiguous(Sides,MPI_UNSIGNED,&My_MPI_JobLine);    
MPI_Type_commit(&My_MPI_JobLine);    
Row = MyID/SqrtProcs;    
Column = MyID%SqrtProcs;    
tag = 1;    
if(MyID == 0){
	ReadFile();       
	Floyd_InitPath();                
	for( i = 0 ; i < NumProcs ; i++ )        {
		tempblock = GetJobArray(i);            
		ArrayConvertToBuff(Sides,Sides,tempblock->array);           
		MPI_Send(Buff, 1, My_MPI_JobArr, i, tag, MPI_COMM_WORLD);            
		NArray_Free(tempblock);        
		}    
	}    
//printf("%d/t%d/t%d/t%d/t/n",Sides,NumProcs,SqrtProcs,Nodes);    
JobArray.array = CreateArray(Sides, Sides);    
MPI_Recv(Buff ,1 ,My_MPI_JobArr , 0 , tag ,MPI_COMM_WORLD, &status);    
printf("+++++++++++++++  %u   +++++++++++++++++/n",MyID);    
BuffConvertToArray(Sides,Sides,JobArray.array);    
//Array_Print(Sides,Sides,JobArray.array);            
TempA = CreateArray(1, Sides);    
TempB = CreateArray(1, Sides);    

for(k = 0 ; k < Nodes ; k ++)    {        
	/*发送第k行数据*/        
	int seq = k/Sides;                
	if( seq == MyID/SqrtProcs )        {
		i = k%Sides;            
		for(j = 0 ; j < Sides ; j++)            {
			TempA[0][j] = JobArray.array[i][j];            
			}            
		ArrayConvertToBuff(1,Sides,TempA);            
		for( m  = 0 ; m < SqrtProcs ; m ++)            {                
			//printf("///t%d/t///n",m*SqrtProcs+Column);                
			MPI_Send(Buff, 1, My_MPI_JobLine, m*SqrtProcs+Column, MyID , MPI_COMM_WORLD);            
			}        
}        
MPI_Recv(Buff ,1 ,My_MPI_JobLine , seq*SqrtProcs+Column , seq*SqrtProcs+Column,MPI_COMM_WORLD, &status);        
BuffConvertToArray(1,Sides,TempA);        
//Array_Print(1,Sides,TempA);        
/*发送第k列数据*/        
if( seq == MyID%SqrtProcs)        {           
	i = k%Sides;            
	for(j = 0 ; j < Sides ; j++)            {                
		TempB[0][j] = JobArray.array[j][i];            
		}            
	ArrayConvertToBuff(1,Sides,TempB);            
	for( m  = 0 ; m < SqrtProcs ; m ++)            {                
		//printf("///t%d/t///n",Row*SqrtProcs+m);                
		MPI_Send(Buff, 1, My_MPI_JobLine, Row*SqrtProcs+m, MyID , MPI_COMM_WORLD);            
		}        
}      

MPI_Recv(Buff ,1 ,My_MPI_JobLine , Row*SqrtProcs+seq , Row*SqrtProcs+seq,MPI_COMM_WORLD, &status);        
BuffConvertToArray(1,Sides,TempB);        
		//Array_Print(1,Sides,TempB);        
		/*各个块内进行运算*/        
for(i = 0 ; i <Sides ; i++ )        {            
			for(j = 0 ; j <Sides ; j++)            {                
				if(JobArray.array[i][j]> (TempB[0][i] + TempA[0][j]))                    
				JobArray.array[i][j] =  TempB[0][i] + TempA[0][j];                
				if(JobArray.array[i][j]>METRY_MAX)                    
					JobArray.array[i][j] = METRY_MAX;            
					}        
				}    
}    


			ArrayConvertToBuff(Sides,Sides,JobArray.array);    
			TempEndBuff = (unsigned int*)malloc(Nodes*Nodes*sizeof(unsigned int));    
			MPI_Gather(Buff, Sides*Sides, MPI_UNSIGNED,&TempEndBuff[MyID*Sides*Sides], Sides*Sides, MPI_UNSIGNED, 0, MPI_COMM_WORLD);    
			if(MyID == 0)    {            
				m = 0;            
				for( k = 0 ; k < NumProcs ; k++)                
				for(i = 0 ; i < Sides ; i++)               
				 {                    for(j = 0 ; j < Sides ; j++)                    {
					                         Array[i+k/SqrtProcs*Sides][j+k%SqrtProcs*Sides] = TempEndBuff[m++];                     }                }
											             printf("n");            
														 Array_Print(Nodes,Nodes,Array);                       } 
														    
					//printf("%d/n",Sides);    
					free(TempEndBuff);    
					FreeArray(1,Sides,TempA);   
					 FreeArray(1,Sides,TempB);    
					 FreeArray(Sides,Sides,JobArray.array);    
					 if(MyID == 0)    {        
						 FreeArray(Nodes , Nodes, Path);        
						 FreeArray(Nodes , Nodes, Array);        
						 endwtime = MPI_Wtime();        
						 printf("wall clock time = %f/n", endwtime-startwtime);    }    
					fprintf(stderr,"Process %d on %s/n",        MyID, processor_name);    
					MPI_Type_free(&My_MPI_JobArr);    
					MPI_Type_free(&My_MPI_JobLine);    
					/*MPI finalize*/    
					MPI_Finalize();
