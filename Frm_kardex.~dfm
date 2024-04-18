object Form_kardex: TForm_kardex
  Left = 259
  Top = 140
  Width = 696
  Height = 480
  Caption = 'Form_kardex'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object qry_inven: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select codigo,cod2,descri,tipo,prove,linea,empaqe,minimo,maximo,'
      
        'precio,piva,costos,coston,inicials,entcoms,entcans,entesps,salvt' +
        'as,'
      
        'salfons,salesps,salmays,existes,inicialn,entcomn,entcann,entespn' +
        ','
      'salvtan,salfonn,salespn,salmayn,existen,cosinicials,cosentcoms,'
      
        'cosentcans,cosentesps,cossalvtas,cossalfons,cossalesps,cossalmay' +
        's,'
      
        'cosexistes,cosinicialn,cosentcomn,cosentcann,cosentespn,cossalvt' +
        'an,'
      
        'cossalfonn,cossalespn,cossalmayn,cosexisten,fecalta,cia,mds,elec' +
        ','
      'precelec'
      'from inven where codigo = :CODIGO and cia = :CIA'
      ' ')
    UpdateObject = uqry_inven
    Left = 96
    Top = 80
    ParamData = <
      item
        DataType = ftString
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object uqry_inven: TUpdateSQL
    ModifySQL.Strings = (
      'update inven'
      'set'
      '  COD2 = :COD2,'
      '  DESCRI = :DESCRI,'
      '  TIPO = :TIPO,'
      '  PROVE = :PROVE,'
      '  LINEA = :LINEA,'
      '  EMPAQE = :EMPAQE,'
      '  MINIMO = :MINIMO,'
      '  MAXIMO = :MAXIMO,'
      '  PRECIO = :PRECIO,'
      '  PIVA = :PIVA,'
      '  COSTOS = :COSTOS,'
      '  COSTON = :COSTON,'
      '  INICIALS = :INICIALS,'
      '  ENTCOMS = :ENTCOMS,'
      '  ENTCANS = :ENTCANS,'
      '  ENTESPS = :ENTESPS,'
      '  SALVTAS = :SALVTAS,'
      '  SALFONS = :SALFONS,'
      '  SALESPS = :SALESPS,'
      '  SALMAYS = :SALMAYS,'
      '  EXISTES = :EXISTES,'
      '  INICIALN = :INICIALN,'
      '  ENTCOMN = :ENTCOMN,'
      '  ENTCANN = :ENTCANN,'
      '  ENTESPN = :ENTESPN,'
      '  SALVTAN = :SALVTAN,'
      '  SALFONN = :SALFONN,'
      '  SALESPN = :SALESPN,'
      '  SALMAYN = :SALMAYN,'
      '  EXISTEN = :EXISTEN,'
      '  COSINICIALS = :COSINICIALS,'
      '  COSENTCOMS = :COSENTCOMS,'
      '  COSENTCANS = :COSENTCANS,'
      '  COSENTESPS = :COSENTESPS,'
      '  COSSALVTAS = :COSSALVTAS,'
      '  COSSALFONS = :COSSALFONS,'
      '  COSSALESPS = :COSSALESPS,'
      '  COSSALMAYS = :COSSALMAYS,'
      '  COSEXISTES = :COSEXISTES,'
      '  COSINICIALN = :COSINICIALN,'
      '  COSENTCOMN = :COSENTCOMN,'
      '  COSENTCANN = :COSENTCANN,'
      '  COSENTESPN = :COSENTESPN,'
      '  COSSALVTAN = :COSSALVTAN,'
      '  COSSALFONN = :COSSALFONN,'
      '  COSSALESPN = :COSSALESPN,'
      '  COSSALMAYN = :COSSALMAYN,'
      '  COSEXISTEN = :COSEXISTEN,'
      '  FECALTA = :FECALTA,'
      '  MDS = :MDS,'
      '  ELEC = :ELEC,'
      '  PRECELEC = :PRECELEC'
      'where'
      '  CODIGO = :OLD_CODIGO and'
      '  CIA = :OLD_CIA')
    InsertSQL.Strings = (
      'insert into inven'
      
        '  (CODIGO, COD2, DESCRI, TIPO, PROVE, LINEA, EMPAQE, MINIMO, MAX' +
        'IMO, '
      'PRECIO, '
      '   PIVA, COSTOS, COSTON, INICIALS, ENTCOMS, ENTCANS, ENTESPS, '
      'SALVTAS, '
      
        '   SALFONS, SALESPS, SALMAYS, EXISTES, INICIALN, ENTCOMN, ENTCAN' +
        'N, '
      'ENTESPN, '
      '   SALVTAN, SALFONN, SALESPN, SALMAYN, EXISTEN, COSINICIALS, '
      'COSENTCOMS, '
      '   COSENTCANS, COSENTESPS, COSSALVTAS, COSSALFONS, COSSALESPS, '
      'COSSALMAYS, '
      '   COSEXISTES, COSINICIALN, COSENTCOMN, COSENTCANN, COSENTESPN, '
      'COSSALVTAN, '
      
        '   COSSALFONN, COSSALESPN, COSSALMAYN, COSEXISTEN, FECALTA, CIA,' +
        ' '
      'MDS, ELEC, '
      '   PRECELEC)'
      'values'
      
        '  (:CODIGO, :COD2, :DESCRI, :TIPO, :PROVE, :LINEA, :EMPAQE, :MIN' +
        'IMO, '
      ':MAXIMO, '
      
        '   :PRECIO, :PIVA, :COSTOS, :COSTON, :INICIALS, :ENTCOMS, :ENTCA' +
        'NS, '
      ':ENTESPS, '
      
        '   :SALVTAS, :SALFONS, :SALESPS, :SALMAYS, :EXISTES, :INICIALN, ' +
        ':ENTCOMN, '
      '   :ENTCANN, :ENTESPN, :SALVTAN, :SALFONN, :SALESPN, :SALMAYN, '
      ':EXISTEN, '
      
        '   :COSINICIALS, :COSENTCOMS, :COSENTCANS, :COSENTESPS, :COSSALV' +
        'TAS, '
      ':COSSALFONS, '
      
        '   :COSSALESPS, :COSSALMAYS, :COSEXISTES, :COSINICIALN, :COSENTC' +
        'OMN, '
      ':COSENTCANN, '
      '   :COSENTESPN, :COSSALVTAN, :COSSALFONN, :COSSALESPN, '
      ':COSSALMAYN, :COSEXISTEN, '
      '   :FECALTA, :CIA, :MDS, :ELEC, :PRECELEC)')
    DeleteSQL.Strings = (
      'delete from inven'
      'where'
      '  CODIGO = :OLD_CODIGO and'
      '  CIA = :OLD_CIA')
    Left = 96
    Top = 117
  end
  object qry_exist: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select codigo,alm,inicials,entcoms,entcans,entesps,salvtas,salfo' +
        'ns,'
      
        'salesps,salmays,existes,inicialn,entcomn,entcann,entespn,salvtan' +
        ','
      
        'salfonn,salespn,salmayn,existen,cosinicials,cosentcoms,cosentcan' +
        's,'
      
        'cosentesps,cossalvtas,cossalfons,cossalesps,cosexistes,cosinicia' +
        'ln,'
      
        'cosentcomn,cosentcann,cosentespn,cossalvtan,cossalfonn,cossalesp' +
        'n,'
      'cossalmayn,cosexisten,ultfol,cia'
      
        'from exist where codigo = :CODIGO and ( alm = :ALMSALE or alm = ' +
        ':ALMENTRA) '
      'and cia = :CIA')
    UpdateObject = uqry_exist
    Left = 128
    Top = 80
    ParamData = <
      item
        DataType = ftString
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'ALMSALE'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'ALMENTRA'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object uqry_exist: TUpdateSQL
    ModifySQL.Strings = (
      'update exist'
      'set'
      '  INICIALS = :INICIALS,'
      '  ENTCOMS = :ENTCOMS,'
      '  ENTCANS = :ENTCANS,'
      '  ENTESPS = :ENTESPS,'
      '  SALVTAS = :SALVTAS,'
      '  SALFONS = :SALFONS,'
      '  SALESPS = :SALESPS,'
      '  SALMAYS = :SALMAYS,'
      '  EXISTES = :EXISTES,'
      '  INICIALN = :INICIALN,'
      '  ENTCOMN = :ENTCOMN,'
      '  ENTCANN = :ENTCANN,'
      '  ENTESPN = :ENTESPN,'
      '  SALVTAN = :SALVTAN,'
      '  SALFONN = :SALFONN,'
      '  SALESPN = :SALESPN,'
      '  SALMAYN = :SALMAYN,'
      '  EXISTEN = :EXISTEN,'
      '  COSINICIALS = :COSINICIALS,'
      '  COSENTCOMS = :COSENTCOMS,'
      '  COSENTCANS = :COSENTCANS,'
      '  COSENTESPS = :COSENTESPS,'
      '  COSSALVTAS = :COSSALVTAS,'
      '  COSSALFONS = :COSSALFONS,'
      '  COSSALESPS = :COSSALESPS,'
      '  COSEXISTES = :COSEXISTES,'
      '  COSINICIALN = :COSINICIALN,'
      '  COSENTCOMN = :COSENTCOMN,'
      '  COSENTCANN = :COSENTCANN,'
      '  COSENTESPN = :COSENTESPN,'
      '  COSSALVTAN = :COSSALVTAN,'
      '  COSSALFONN = :COSSALFONN,'
      '  COSSALESPN = :COSSALESPN,'
      '  COSSALMAYN = :COSSALMAYN,'
      '  COSEXISTEN = :COSEXISTEN,'
      '  ULTFOL = :ULTFOL'
      'where'
      '  CODIGO = :OLD_CODIGO and'
      '  ALM = :OLD_ALM and'
      '  CIA = :OLD_CIA')
    InsertSQL.Strings = (
      'insert into exist'
      '  (CODIGO, ALM, INICIALS, ENTCOMS, ENTCANS, ENTESPS, SALVTAS, '
      'SALFONS, '
      
        '   SALESPS, SALMAYS, EXISTES, INICIALN, ENTCOMN, ENTCANN, ENTESP' +
        'N, '
      'SALVTAN, '
      '   SALFONN, SALESPN, SALMAYN, EXISTEN, COSINICIALS, COSENTCOMS, '
      'COSENTCANS, '
      '   COSENTESPS, COSSALVTAS, COSSALFONS, COSSALESPS, COSEXISTES, '
      'COSINICIALN, '
      '   COSENTCOMN, COSENTCANN, COSENTESPN, COSSALVTAN, COSSALFONN, '
      'COSSALESPN, '
      '   COSSALMAYN, COSEXISTEN, ULTFOL, CIA)'
      'values'
      
        '  (:CODIGO, :ALM, :INICIALS, :ENTCOMS, :ENTCANS, :ENTESPS, :SALV' +
        'TAS, '
      ':SALFONS, '
      '   :SALESPS, :SALMAYS, :EXISTES, :INICIALN, :ENTCOMN, :ENTCANN, '
      ':ENTESPN, '
      
        '   :SALVTAN, :SALFONN, :SALESPN, :SALMAYN, :EXISTEN, :COSINICIAL' +
        'S, '
      ':COSENTCOMS, '
      
        '   :COSENTCANS, :COSENTESPS, :COSSALVTAS, :COSSALFONS, :COSSALES' +
        'PS, '
      ':COSEXISTES, '
      '   :COSINICIALN, :COSENTCOMN, :COSENTCANN, :COSENTESPN, '
      ':COSSALVTAN, :COSSALFONN, '
      '   :COSSALESPN, :COSSALMAYN, :COSEXISTEN, :ULTFOL, :CIA)')
    DeleteSQL.Strings = (
      'delete from exist'
      'where'
      '  CODIGO = :OLD_CODIGO and'
      '  ALM = :OLD_ALM and'
      '  CIA = :OLD_CIA')
    Left = 128
    Top = 117
  end
  object qry_movart: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select codigo,almac,folio,prove,nompro,compro,facpro,fecha,costo' +
        ','
      
        'sespe,modsal,modent,nentrada,tipo,vienede,folviene,vahacia,folre' +
        'c,'
      'pueblo,numfac,seriefac,salio,smay,fechasal,canti,serie,salvta,'
      'entcan,nsalida,entrapor,salepor,fecentori,fecvencto,usuario,cia,'
      'ptvta,vend'
      'from movart'
      'where '
      'codigo = :CODIGO '
      
        'and ( ( almac = :ALM and folio = :FOLIO ) or ( almac = :ALMENT a' +
        'nd folio = :FOLENT ) )'
      'and cia = :CIA')
    UpdateObject = uqry_movart
    Left = 160
    Top = 82
    ParamData = <
      item
        DataType = ftString
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'ALM'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'FOLIO'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'ALMENT'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'FOLENT'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object uqry_movart: TUpdateSQL
    ModifySQL.Strings = (
      'update movart'
      'set'
      '  CODIGO = :CODIGO,'
      '  ALMAC = :ALMAC,'
      '  FOLIO = :FOLIO,'
      '  PROVE = :PROVE,'
      '  NOMPRO = :NOMPRO,'
      '  COMPRO = :COMPRO,'
      '  FACPRO = :FACPRO,'
      '  FECHA = :FECHA,'
      '  COSTO = :COSTO,'
      '  SESPE = :SESPE,'
      '  MODSAL = :MODSAL,'
      '  MODENT = :MODENT,'
      '  NENTRADA = :NENTRADA,'
      '  TIPO = :TIPO,'
      '  VIENEDE = :VIENEDE,'
      '  FOLVIENE = :FOLVIENE,'
      '  VAHACIA = :VAHACIA,'
      '  FOLREC = :FOLREC,'
      '  PUEBLO = :PUEBLO,'
      '  NUMFAC = :NUMFAC,'
      '  SERIEFAC = :SERIEFAC,'
      '  SALIO = :SALIO,'
      '  SMAY = :SMAY,'
      '  FECHASAL = :FECHASAL,'
      '  CANTI = :CANTI,'
      '  SERIE = :SERIE,'
      '  SALVTA = :SALVTA,'
      '  ENTCAN = :ENTCAN,'
      '  NSALIDA = :NSALIDA,'
      '  ENTRAPOR = :ENTRAPOR,'
      '  SALEPOR = :SALEPOR,'
      '  FECENTORI = :FECENTORI,'
      '  FECVENCTO = :FECVENCTO,'
      '  USUARIO = :USUARIO,'
      '  CIA = :CIA,'
      '  PTVTA = :PTVTA,'
      '  VEND = :VEND'
      'where'
      '  CODIGO = :OLD_CODIGO and'
      '  ALMAC = :OLD_ALMAC and'
      '  FOLIO = :OLD_FOLIO and'
      '  CIA = :OLD_CIA')
    InsertSQL.Strings = (
      'insert into movart'
      '  (CODIGO, ALMAC, FOLIO, PROVE, NOMPRO, COMPRO, FACPRO, FECHA, '
      'COSTO, SESPE, '
      '   MODSAL, MODENT, NENTRADA, TIPO, VIENEDE, FOLVIENE, VAHACIA, '
      'FOLREC, '
      
        '   PUEBLO, NUMFAC, SERIEFAC, SALIO, SMAY, FECHASAL, CANTI, SERIE' +
        ', '
      'SALVTA, '
      '   ENTCAN, NSALIDA, ENTRAPOR, SALEPOR, FECENTORI, FECVENCTO, '
      'USUARIO, CIA, '
      '   PTVTA, VEND)'
      'values'
      
        '  (:CODIGO, :ALMAC, :FOLIO, :PROVE, :NOMPRO, :COMPRO, :FACPRO, :' +
        'FECHA, '
      
        '   :COSTO, :SESPE, :MODSAL, :MODENT, :NENTRADA, :TIPO, :VIENEDE,' +
        ' '
      ':FOLVIENE, '
      
        '   :VAHACIA, :FOLREC, :PUEBLO, :NUMFAC, :SERIEFAC, :SALIO, :SMAY' +
        ', '
      ':FECHASAL, '
      
        '   :CANTI, :SERIE, :SALVTA, :ENTCAN, :NSALIDA, :ENTRAPOR, :SALEP' +
        'OR, '
      ':FECENTORI, '
      '   :FECVENCTO, :USUARIO, :CIA, :PTVTA, :VEND)')
    DeleteSQL.Strings = (
      'delete from movart'
      'where'
      '  CODIGO = :OLD_CODIGO and'
      '  ALMAC = :OLD_ALMAC and'
      '  FOLIO = :OLD_FOLIO and'
      '  CIA = :OLD_CIA')
    Left = 160
    Top = 119
  end
  object qry_estadis: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select tipo,codigo,alm,anu,mes,unidades,importe,cia'
      'from estadis'
      'where tipo = :TIPOEST and codigo = :CODIGO and alm = :ALM'
      'and anu = :ANU and mes = :MES and cia = :CIA'
      '')
    UpdateObject = uqry_estadis
    Left = 192
    Top = 82
    ParamData = <
      item
        DataType = ftInteger
        Name = 'TIPOEST'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'ALM'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'ANU'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'MES'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object uqry_estadis: TUpdateSQL
    ModifySQL.Strings = (
      'update estadis'
      'set'
      '  UNIDADES = :UNIDADES,'
      '  IMPORTE = :IMPORTE'
      'where'
      '  TIPO = :OLD_TIPO and'
      '  CODIGO = :OLD_CODIGO and'
      '  ALM = :OLD_ALM and'
      '  ANU = :OLD_ANU and'
      '  MES = :OLD_MES and'
      '  CIA = :OLD_CIA')
    InsertSQL.Strings = (
      'insert into estadis'
      '  (TIPO, CODIGO, ALM, ANU, MES, UNIDADES, IMPORTE, CIA)'
      'values'
      '  (:TIPO, :CODIGO, :ALM, :ANU, :MES, :UNIDADES, :IMPORTE, :CIA)')
    DeleteSQL.Strings = (
      'delete from estadis'
      'where'
      '  TIPO = :OLD_TIPO and'
      '  CODIGO = :OLD_CODIGO and'
      '  ALM = :OLD_ALM and'
      '  ANU = :OLD_ANU and'
      '  MES = :OLD_MES and'
      '  CIA = :OLD_CIA')
    Left = 192
    Top = 119
  end
  object ActionList1: TActionList
    Left = 120
    Top = 184
  end
  object qry_renentra: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select tipo, alm, numero, conse, recemi, codinv, folsal, folent,' +
        ' vend, costou, importe, piva, status, siono, cia'
      'from renentra'
      
        'where tipo = :TIPO and alm = :ALM and numero = :NUMERO and conse' +
        ' = :NUMREN and'
      'cia = :CIA')
    UpdateObject = uqry_renentra
    Left = 224
    Top = 82
    ParamData = <
      item
        DataType = ftString
        Name = 'TIPO'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'ALM'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'NUMERO'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'NUMREN'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object uqry_renentra: TUpdateSQL
    ModifySQL.Strings = (
      'update renentra'
      'set'
      '  RECEMI = :RECEMI,'
      '  CODINV = :CODINV,'
      '  FOLSAL = :FOLSAL,'
      '  FOLENT = :FOLENT,'
      '  COSTOU = :COSTOU,'
      '  IMPORTE = :IMPORTE,'
      '  PIVA = :PIVA,'
      '  STATUS = :STATUS,'
      '  SIONO = :SIONO'
      'where'
      '  TIPO = :OLD_TIPO and'
      '  ALM = :OLD_ALM and'
      '  NUMERO = :OLD_NUMERO and'
      '  CONSE = :OLD_CONSE and'
      '  CIA = :OLD_CIA')
    InsertSQL.Strings = (
      'insert into renentra'
      
        '  (RECEMI, CODINV, FOLSAL, FOLENT, COSTOU, IMPORTE, PIVA, STATUS' +
        ', '
      'SIONO)'
      'values'
      
        '  (:RECEMI, :CODINV, :FOLSAL, :FOLENT, :COSTOU, :IMPORTE, :PIVA,' +
        ' :STATUS, '
      '   :SIONO)')
    DeleteSQL.Strings = (
      'delete from renentra'
      'where'
      '  TIPO = :OLD_TIPO and'
      '  ALM = :OLD_ALM and'
      '  NUMERO = :OLD_NUMERO and'
      '  CONSE = :OLD_CONSE and'
      '  CIA = :OLD_CIA')
    Left = 224
    Top = 119
  end
  object qry_almacen: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select clave, nombre from Almacen where'
      
        '( clave = :ALMREC or clave = :ALMENV) and Cia = :Cia order by cl' +
        'ave'
      '')
    Left = 64
    Top = 80
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'ALMREC'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'ALMENV'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'Cia'
        ParamType = ptUnknown
      end>
  end
  object qry_ultfol: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select ultfol from exist '
      'where alm = :ALMREC and  codigo = :CODIGO and Cia = :Cia'
      '')
    Left = 62
    Top = 117
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'ALMREC'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'Cia'
        ParamType = ptUnknown
      end>
  end
  object qry_invulcos: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select codigo, fecha, costos, coston, cia'
      'from invulcos'
      'where codigo = :CODIGO and fecha = :FECHA and cia = :CIA')
    UpdateObject = uqry_invulcos
    Left = 256
    Top = 82
    ParamData = <
      item
        DataType = ftString
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECHA'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object uqry_invulcos: TUpdateSQL
    ModifySQL.Strings = (
      'update invulcos'
      'set'
      '  COSTOS = :COSTOS,'
      '  COSTON = :COSTON'
      'where'
      '  CODIGO = :OLD_CODIGO and'
      '  FECHA = :OLD_FECHA and'
      '  CIA = :OLD_CIA')
    InsertSQL.Strings = (
      'insert into invulcos'
      '  (CODIGO, FECHA, COSTOS, COSTON, CIA)'
      'values'
      '  (:CODIGO, :FECHA, :COSTOS, :COSTON, :CIA)')
    DeleteSQL.Strings = (
      'delete from invulcos'
      'where'
      '  CODIGO = :OLD_CODIGO and'
      '  FECHA = :OLD_FECHA and'
      '  CIA = :OLD_CIA')
    Left = 256
    Top = 119
  end
end
