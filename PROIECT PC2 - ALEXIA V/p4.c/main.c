#include <stdio.h>
#include <stdlib.h>

struct autoturism{
    char numarInmatriculare[15];
    char marca[20];
    char culoare[20];
    int numarLocuri;
    char tipCombustibil[20];
    int capacitate;
    char serieSasiu[30];
    int vechime;
    int km;
};

void afisaremasini(const char *filename)
{
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        printf("Eroare!\n");
        return;
    }
    struct autoturism car;
    while (fread(&car, sizeof(struct autoturism), 1, fp) == 1)
    {
        printf("%s {\n", car.numarInmatriculare);
        printf("Marca: %s\n", car.marca);
        printf("Culoare: %s\n", car.culoare);
        printf("Numar locuri: %d\n", car.numarLocuri);
        printf("Tip combustibil: %s\n", car.tipCombustibil);
        printf("Capacitate: %d\n", car.capacitate);
        printf("Serie sasiu: %s\n", car.serieSasiu);
        printf("Vechime: %d\n", car.vechime);
        printf("Km: %d\n", car.km);
        printf("}\n");
    }
    fclose(fp);
}

int arenumardeinmatriculare(const char *filename, const char *numarInmatriculare)
{
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        printf("Eroare!\n");
        return 0;
    }
    struct autoturism car;
    while (fread(&car, sizeof(struct autoturism), 1, fp) == 1)
    {
        if (strcmp(car.numarInmatriculare, numarInmatriculare) == 0)
        {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

void modificamasina(const char *filename, const char *numarInmatriculare)
 {
    FILE *fp = fopen(filename, "r+b");
    if (fp == NULL)
    {
        printf("Eroare!\n");
        return;
    }
    struct autoturism car;
    while (fread(&car, sizeof(struct autoturism), 1, fp) == 1)
        {
        if (strcmp(car.numarInmatriculare, numarInmatriculare) == 0)
            {
            printf("Introduceti numarul de km modificati: ");
            scanf("%d", &car.km);
            printf("Introduceti vechime noua: ");
            scanf("%d", &car.vechime);
            fseek(fp, -(long)sizeof(struct autoturism), SEEK_CUR);
            fwrite(&car, sizeof(struct autoturism), 1, fp);
            break;
            }
        }
    fclose(fp);
}

void adaugamasina(const char *filename)
{
    FILE *fp = fopen(filename, "ab");
    if (fp == NULL)
    {
        printf("Eroare!\n");
        return;
    }
    while (1)
    {
        FILE *fp = fopen(filename, "ab");
        struct autoturism car;
        printf("Introduceti numarul de inmatriculare (-1 pentru a iesi din meniul de ADAUGAMASINA): ");
        scanf("%s", car.numarInmatriculare);
        if (strcmp(car.numarInmatriculare, "-1") == 0)
         {
            break;
         }
        if (arenumardeinmatriculare(filename, car.numarInmatriculare))
         {
            printf("O masina cu acest numar inmatriculare exista deja\n");
            continue;
         }
        printf("Introduceti marca: ");
        scanf("%s", car.marca);

        printf("Introduceti culoare: ");
        scanf("%s", car.culoare);

        printf("Introduceti numar locuri: ");
        scanf("%d", &car.numarLocuri);

        printf("Introduceti tip combustibil: ");
        scanf("%s", car.tipCombustibil);

        printf("Introduceti capacitate: ");
        scanf("%d", &car.capacitate);

        printf("Introduceti serie sasiu: ");
        scanf("%s", car.serieSasiu);

        printf("Introduceti vechime: ");
        scanf("%d", &car.vechime);

        printf("Introduceti km: ");
        scanf("%d", &car.km);

        fwrite(&car, sizeof(struct autoturism), 1, fp);
        fclose(fp);
    }
    fclose(fp);
}

void initiere()
{
     adaugamasina("masini.bin");
     modificamasina("masini.bin","B202SLA");
     //In al doilea camp se introduce numarul de inmatriculare al masinii careia doriti sa ii modificati VECHIME & NR DE KM
     afisaremasini("masini.bin");
}

int main()
{
    initiere();
    return 0;
}
