#include "ENCA.h"

// computation analyses against different internal encodings
void Test_different_encodings()
{
    uint8_t map[total][256];
    FILE *fp;
    int count;
    for(int Case = 1; Case <= 14; Case++)
    {
        for(int Test = 0; Test < total; Test++)
        {
            generate_map(map[Test], Case);
        }

        //-----DCA-----
        count = 0; 
        for(int Test = 0; Test < total; Test++)
        {
            if((((Test + 1) % (int)(total * 0.2)) == 0) && (Test < total - 1)) printf("processing: %d\%\n", (Test + 1) * 100 / total);
            if(DCA(map[Test])) count++;
        }
        printf("DCA #%d broken tests: %d\n", Case, count);
        fp = fopen("DCA_distinguisher.txt", "a");
        fprintf(fp, "DCA #%d broken tests: %d\n", Case, count);
        fclose(fp);

        //-----IDCA-----
        count = 0; 
        for(int Test = 0; Test < total; Test++)
        {
            if((((Test + 1) % (int)(total * 0.2)) == 0) && (Test < total - 1)) printf("processing: %d\%\n", (Test + 1) * 100 / total);
            if(IDCA(map[Test])) count++;
        }
        printf("IDCA #%d broken tests: %d\n", Case, count);
        fp = fopen("IDCA_distinguisher.txt", "a");
        fprintf(fp, "IDCA #%d broken tests: %d\n", Case, count);
        fclose(fp);

        //-----CPA-----
        count = 0; 
        for(int Test = 0; Test < total; Test++)
        {
            if((((Test + 1) % (int)(total * 0.2)) == 0) && (Test < total - 1)) printf("processing: %d\%\n", (Test + 1) * 100 / total);
            if(CPA(map[Test])) count++;
        }
        printf("CPA #%d broken tests: %d\n", Case, count);
        fp = fopen("CPA_distinguisher.txt", "a");
        fprintf(fp, "CPA #%d broken tests: %d\n", Case, count);
        fclose(fp);

        //-----CA-----
        count = 0; 
        for(int Test = 0; Test < total; Test++)
        {
            if((((Test + 1) % (int)(total * 0.2)) == 0) && (Test < total - 1)) printf("processing: %d\%\n", (Test + 1) * 100 / total);
            if(CA(map[Test])) count++;
        }
        printf("CA #%d broken tests: %d\n", Case, count);
        fp = fopen("CA_distinguisher.txt", "a");
        fprintf(fp, "CA #%d broken tests: %d\n", Case, count);
        fclose(fp);

        //-----MIA-----
        count = 0; 
        for(int Test = 0; Test < total; Test++)
        {
            if((((Test + 1) % (int)(total * 0.2)) == 0) && (Test < total - 1)) printf("processing: %d\%\n", (Test + 1) * 100 / total);
            if(MIA(map[Test])) count++;
        }
        printf("MIA #%d broken tests: %d\n", Case, count);
        fp = fopen("MIA_distinguisher.txt", "a");
        fprintf(fp, "MIA #%d broken tests: %d\n", Case, count);
        fclose(fp);

        //-----SA-----
        count = 0; 
        for(int Test = 0; Test < total; Test++)
        {
            if((((Test + 1) % (int)(total * 0.2)) == 0) && (Test < total - 1)) printf("processing: %d\%\n", (Test + 1) * 100 / total);
            if(SA(map[Test])) count++;
        }
        printf("SA #%d broken tests: %d\n", Case, count);
        fp = fopen("SA_distinguisher.txt", "a");
        fprintf(fp, "SA #%d broken tests: %d\n", Case, count);
        fclose(fp);
      
        //-----MSA-----
        count = 0; 
        for(int Test = 0; Test < total; Test++)
        {
            if((((Test + 1) % (int)(total * 0.2)) == 0) && (Test < total - 1)) printf("processing: %d\%\n", (Test + 1) * 100 / total);
            if(MSA(map[Test])) count++;
        }
        printf("MSA #%d broken tests: %d\n", Case, count);
        fp = fopen("MSA_distinguisher.txt", "a");
        fprintf(fp, "MSA #%d broken tests: %d\n", Case, count);
        fclose(fp);
        
        //-----ISA-----
        count = 0; 
        for(int Test = 0; Test < total; Test++)
        {
            if((((Test + 1) % (int)(total * 0.2)) == 0) && (Test < total - 1)) printf("processing: %d\%\n", (Test + 1) * 100 / total);
            if(ISA(map[Test])) count++;
        }
        printf("ISA #%d broken tests: %d\n", Case, count);
        fp = fopen("ISA_distinguisher.txt", "a");
        fprintf(fp, "ISA #%d broken tests: %d\n", Case, count);
        fclose(fp);
        
        //-----ADCA-----
        count = 0; 
        for(int Test = 0; Test < total; Test++)
        {
            if((((Test + 1) % (int)(total * 0.2)) == 0) && (Test < total - 1)) printf("processing: %d\%\n", (Test + 1) * 100 / total);
            if(ADCA(map[Test], 6)) count++;
        }
        printf("ADCA #%d broken tests: %d\n", Case, count);
        fp = fopen("ADCA_distinguisher.txt", "a");
        fprintf(fp, "ADCA #%d broken tests: %d\n", Case, count);
        fclose(fp);
    }
}

// computation analyses against internal encodings with different algebraic degrees
void Test_different_degrees()
{
    uint8_t map[total][256];
    FILE *fp;
    int count;
    for(int Case = 1; Case <= 7; Case++)
    {

        for(int Test = 0; Test < total; Test++)
        {
            generate_map_degree(map[Test], Case);
        }

        //-----DCA-----
        count = 0; 
        for(int Test = 0; Test < total; Test++)
        {
            if((((Test + 1) % (int)(total * 0.2)) == 0) && (Test < total - 1)) printf("processing: %d\%\n", (Test + 1) * 100 / total);
            if(DCA(map[Test])) count++;
        }
        printf("DCA #%d broken tests: %d\n", Case, count);
        fp = fopen("DCA_distinguisher.txt", "a");
        fprintf(fp, "DCA #%d broken tests: %d\n", Case, count);
        fclose(fp);

        //-----IDCA-----
        count = 0; 
        for(int Test = 0; Test < total; Test++)
        {
            if((((Test + 1) % (int)(total * 0.2)) == 0) && (Test < total - 1)) printf("processing: %d\%\n", (Test + 1) * 100 / total);
            if(IDCA(map[Test])) count++;
        }
        printf("IDCA #%d broken tests: %d\n", Case, count);
        fp = fopen("IDCA_distinguisher.txt", "a");
        fprintf(fp, "IDCA #%d broken tests: %d\n", Case, count);
        fclose(fp);

        //-----CPA-----
        count = 0; 
        for(int Test = 0; Test < total; Test++)
        {
            if((((Test + 1) % (int)(total * 0.2)) == 0) && (Test < total - 1)) printf("processing: %d\%\n", (Test + 1) * 100 / total);
            if(CPA(map[Test])) count++;
        }
        printf("CPA #%d broken tests: %d\n", Case, count);
        fp = fopen("CPA_distinguisher.txt", "a");
        fprintf(fp, "CPA #%d broken tests: %d\n", Case, count);
        fclose(fp);

        //-----CA-----
        count = 0; 
        for(int Test = 0; Test < total; Test++)
        {
            if((((Test + 1) % (int)(total * 0.2)) == 0) && (Test < total - 1)) printf("processing: %d\%\n", (Test + 1) * 100 / total);
            if(CA(map[Test])) count++;
        }
        printf("CA #%d broken tests: %d\n", Case, count);
        fp = fopen("CA_distinguisher.txt", "a");
        fprintf(fp, "CA #%d broken tests: %d\n", Case, count);
        fclose(fp);

        //-----MIA-----
        count = 0; 
        for(int Test = 0; Test < total; Test++)
        {
            if((((Test + 1) % (int)(total * 0.2)) == 0) && (Test < total - 1)) printf("processing: %d\%\n", (Test + 1) * 100 / total);
            if(MIA(map[Test])) count++;
        }
        printf("MIA #%d broken tests: %d\n", Case, count);
        fp = fopen("MIA_distinguisher.txt", "a");
        fprintf(fp, "MIA #%d broken tests: %d\n", Case, count);
        fclose(fp);

        //-----SA-----
        count = 0; 
        for(int Test = 0; Test < total; Test++)
        {
            if((((Test + 1) % (int)(total * 0.2)) == 0) && (Test < total - 1)) printf("processing: %d\%\n", (Test + 1) * 100 / total);
            if(SA(map[Test])) count++;
        }
        printf("SA #%d broken tests: %d\n", Case, count);
        fp = fopen("SA_distinguisher.txt", "a");
        fprintf(fp, "SA #%d broken tests: %d\n", Case, count);
        fclose(fp);
    
        //-----MSA-----
        count = 0; 
        for(int Test = 0; Test < total; Test++)
        {
            if((((Test + 1) % (int)(total * 0.2)) == 0) && (Test < total - 1)) printf("processing: %d\%\n", (Test + 1) * 100 / total);
            if(MSA(map[Test])) count++;
        }
        printf("MSA #%d broken tests: %d\n", Case, count);
        fp = fopen("MSA_distinguisher.txt", "a");
        fprintf(fp, "MSA #%d broken tests: %d\n", Case, count);
        fclose(fp);
       
        //-----ISA-----
        count = 0; 
        for(int Test = 0; Test < total; Test++)
        {
            if((((Test + 1) % (int)(total * 0.2)) == 0) && (Test < total - 1)) printf("processing: %d\%\n", (Test + 1) * 100 / total);
            if(ISA(map[Test])) count++;
        }
        printf("ISA #%d broken tests: %d\n", Case, count);
        fp = fopen("ISA_distinguisher.txt", "a");
        fprintf(fp, "ISA #%d broken tests: %d\n", Case, count);
        fclose(fp);
   
        //-----ADCA-----
        count = 0; 
        for(int Test = 0; Test < total; Test++)
        {
            if((((Test + 1) % (int)(total * 0.2)) == 0) && (Test < total - 1)) printf("processing: %d\%\n", (Test + 1) * 100 / total);
            if(ADCA(map[Test], Case)) count++;
        }
        printf("ADCA #%d broken tests: %d\n", Case, count);
        fp = fopen("ADCA_distinguisher.txt", "a");
        fprintf(fp, "ADCA #%d broken tests: %d\n", Case, count);
        fclose(fp);
    }
}

int main()
{
    Test_different_encodings();
    Test_different_degrees();
    return 0;
}