def mailparse(archivo):
    file=open(archivo)
    Lista=file.readlines()
    Mailpars=[]
    campos=['Fecha','Daemon','Proceso','Descripcion']
    for R in Lista:
        Rsplit=R.split(' ')
        time=Rsplit[2].split(':')
        Fecha={'mes':Rsplit[0],'dia':Rsplit[1],'hora':time[0],'min':time[1]}
        if(Rsplit[4].find('[')==-1):
            proceso=Rsplit[4]
            Daemon='dovecot'
        else:
            Daemon=Rsplit[4].split('[')[0]
            proceso=Rsplit[4].split(']')[0].split('[')[1]
        Descripcion=' '.join(map(str,Rsplit[5:]))
        Mailpars.append(dict(zip(campos,[Fecha,Daemon,proceso,Descripcion])))
    file.close()
    return Mailpars

def smtpsent(archivo):
    Lista=mailparse(archivo)
    Post=[]
    for row in Lista:
        if(row['Daemon']=='postfix/smtp' and row['Descripcion'].find('to=<')!=-1):
            mail=row['Descripcion'].split(' ')[1][4:len(row['Descripcion'].split(' ')[1])-2]
            if(mail.find('facebookmail')==-1):
                Post.append({'correo':mail})
    return Post

def pstfixqmgr(archivo):
    Lista=mailparse(archivo)
    Post=[]
    for row in Lista:
        if(row['Daemon']=='postfix/qmgr'):
            if(row['Descripcion'].split(' ')[1].find('from')!=-1):
                sender=row['Descripcion'].split(' ')[1][6:len(row['Descripcion'].split(' ')[1])-2]
            else:
                sender=row['Descripcion'].split(' ')[1][0:len(row['Descripcion'].split(' ')[1])-1]
            if(sender!='' and sender!='removed'):
                Post.append({'emisor':sender})
    return Post

def verificationfail(archivo):
    Lista=mailparse(archivo)
    campos=['ip','hostname']
    Post=[]
    for row in Lista:
        if(row['Descripcion'].find('verification failed')!=-1):
            ip=row['Descripcion'].split(' ')[1]
            hostname=row['Descripcion'].split(' ')[3]
            Post.append(dict(zip(campos,[ip,hostname])))
    return Post


def accessparse(nombre):
    file=open(nombre)
    Lista=file.readlines()
    campos=['IP','RFC','userid','Fecha','zona','request','status','size','Refer','request-header']
    parsed_data=[]
    for R in Lista:
        Rsplit=R.split(' ')
        time=Rsplit[3].split('/')[2].split(':')
        fecha={'dia':Rsplit[3].split('/')[0][1:],'mes':Rsplit[3].split('/')[1],'year':time[0],'hora':time[1],'min':time[2]}
        ip=Rsplit[0]
        rfc=Rsplit[1]
        Uid=Rsplit[2]
        z1=Rsplit[4].split(']')
        zone=Rsplit[4][1:len(Rsplit[4])-1]
        datos=' '.join(map(str,Rsplit[5:]))
        req=datos.split('"')[1]
        stsi=datos.split('"')[2]
        stat=stsi.split(' ')[1]
        siz=stsi.split(' ')[2]
        refer=datos.split('"')[3]
        reqhead=datos.split('"')[5]
        parsed_data.append(dict(zip(campos,[ip,rfc,Uid,fecha,zone,req,stat,siz,refer,reqhead])))
    file.close()
    return parsed_data

def errores(nombre):
    Lista=accessparse(nombre)
    errores=[]
    for item in Lista:
        if(item['status']=='404'):
            errores.append(item)
    return errores

def exitos(nombre):
    Lista=accessparse(nombre)
    success=[]
    for item in Lista:
        if(item['status']=='200'):
            success.append(item)
    return success


def secureparse(nombre_archivo):
    f=open(nombre_archivo)
    Listaf=f.readlines()
    campos=["Fecha","Proceso","Descripcion"]
    LogParse=[]
    for Renglon in Listaf:
        Rsplit=Renglon.split(" ")
        time=Rsplit[2].split(':')
        fecha = {'Mes':Rsplit[0],'dia':Rsplit[1],"hora":time[0],'min':time[1]}
        proceso=Rsplit[4]
        descripcion =' '.join(map(str,Rsplit[5:]))
        Rparse=[fecha,proceso,descripcion]
        LogParse.append(dict(zip(campos,Rparse)))
    f.close()
    return LogParse

def failedpass(nombre):
    S=secureparse(nombre)
    Camposfp=['Usuario','IP','Puerto']
    FP=[]
    for l in S:
        if (l['Descripcion'].find("Failed password")!=-1):
            fp=l['Descripcion'].split('for')[1]
            if(fp.find('from')!=-1):
                if(fp.find('invalid user')!=-1):
                    usuario='invalid user'
                else:
                    usuario=fp.split('from')[0]
                aux=fp.split('from')[1]
                ip=aux.split('port')[0]
                puerto=aux.split('port')[1].split(' ')[1]
            else:
                usuario=fp
                ip=0
                puerto=0
            FP.append(dict(zip(Camposfp,[usuario,ip,puerto])))
    return FP


def userspass(nombre):
    fp=failedpass(nombre)
    User=[]
    for item in fp:
        if(item['Usuario']!=' root ' and item['Usuario']!='invalid user'):
            User.append(item)
    return User

def rootpass(nombre):
    fp=failedpass(nombre)
    campos=['ip','puerto']
    rootfp=[]
    for row in fp:
        if(row['Usuario']==' root '):
            rootfp.append(dict(zip(campos,[row['IP'],row['Puerto']])))
    return rootfp

def authentication_failure(nombre):
    S=secureparse(nombre)
    campos=['rhost','user']
    authfail=[]
    for item in S:
        if(item['Descripcion'].find('authentication failure')!=-1):
            hostuser=item['Descripcion'].split('rhost')
            if(len(hostuser)>1):
                if(len(hostuser[1].split('user'))>1):
                    host=hostuser[1].split('user')[0][1:len(hostuser[1].split('user')[0])-1]
                    user=hostuser[1].split('user')[1][1:len(hostuser[1].split('user')[1])-1]
                else:
                    host=hostuser[1][1:len(hostuser[1])-1]
                    user='no_user_info'
                authfail.append(dict(zip(campos,[host,user])))
    return authfail

def errorparse(nombre):
    S=secureparse(nombre)
    campos=['usuario']
    Errores=[]
    for item in S:
        if(item['Descripcion'].find('error')!=-1):
            descrip=item['Descripcion'].split('error')[1].split(' ')
            user=descrip[5][0:len(descrip[5])-1]
            Errores.append({'usuario':user})
    return Errores


