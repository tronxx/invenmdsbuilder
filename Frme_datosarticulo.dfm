object Frame_datosarticulo: TFrame_datosarticulo
  Left = 0
  Top = 0
  Width = 737
  Height = 263
  TabOrder = 0
  object etiqcodigo: TLabel
    Left = 22
    Top = 16
    Width = 33
    Height = 13
    Caption = '&Codigo'
    FocusControl = edt_codigo
  end
  object lbl_nombre: TLabel
    Left = 178
    Top = 16
    Width = 56
    Height = 13
    Caption = 'Descripcion'
  end
  object Label1: TLabel
    Left = 540
    Top = 16
    Width = 28
    Height = 13
    Caption = 'Línea'
  end
  object Label2: TLabel
    Left = 26
    Top = 40
    Width = 29
    Height = 13
    Caption = 'Grupo'
  end
  object Label3: TLabel
    Left = 196
    Top = 40
    Width = 28
    Height = 13
    Caption = 'Prove'
  end
  object Label4: TLabel
    Left = 377
    Top = 40
    Width = 24
    Height = 13
    Caption = 'Diary'
  end
  object Label5: TLabel
    Left = 547
    Top = 38
    Width = 18
    Height = 13
    Caption = 'Alta'
    FocusControl = edt_alta
  end
  object lbl_prvta: TLabel
    Left = 16
    Top = 62
    Width = 39
    Height = 13
    Caption = 'Costo Si'
  end
  object Label6: TLabel
    Left = 11
    Top = 85
    Width = 44
    Height = 13
    Caption = 'Costo No'
  end
  object Label7: TLabel
    Left = 143
    Top = 62
    Width = 57
    Height = 13
    Caption = 'Precio MDS'
  end
  object Label8: TLabel
    Left = 143
    Top = 86
    Width = 62
    Height = 13
    Caption = 'Precio SUBS'
  end
  object Label9: TLabel
    Left = 9
    Top = 110
    Width = 46
    Height = 13
    Caption = 'Cto.Ext.In'
  end
  object Label10: TLabel
    Left = 143
    Top = 110
    Width = 60
    Height = 13
    Caption = 'Precio C/Ext'
  end
  object Label11: TLabel
    Left = 295
    Top = 62
    Width = 24
    Height = 13
    Caption = 'MUB'
  end
  object Label12: TLabel
    Left = 295
    Top = 86
    Width = 24
    Height = 13
    Caption = 'MUB'
  end
  object Label13: TLabel
    Left = 295
    Top = 110
    Width = 24
    Height = 13
    Caption = 'MUB'
  end
  object Label14: TLabel
    Left = 383
    Top = 62
    Width = 17
    Height = 13
    Caption = 'Min'
  end
  object Label15: TLabel
    Left = 383
    Top = 86
    Width = 20
    Height = 13
    Caption = 'Max'
  end
  object Label16: TLabel
    Left = 449
    Top = 63
    Width = 21
    Height = 13
    Caption = 'Tipo'
  end
  object Label17: TLabel
    Left = 455
    Top = 86
    Width = 15
    Height = 13
    Caption = 'Iva'
  end
  object Label18: TLabel
    Left = 443
    Top = 110
    Width = 26
    Height = 13
    Caption = 'Plazo'
    FocusControl = edt_plazo
  end
  object Label19: TLabel
    Left = 540
    Top = 63
    Width = 30
    Height = 13
    Caption = 'Situac'
  end
  object Label20: TLabel
    Left = 545
    Top = 87
    Width = 30
    Height = 13
    Caption = 'Marca'
  end
  object Label21: TLabel
    Left = 545
    Top = 111
    Width = 21
    Height = 13
    Caption = 'Gtía'
  end
  object Label22: TLabel
    Left = 13
    Top = 136
    Width = 36
    Height = 13
    Caption = 'Descri2'
    FocusControl = edt_descri2
  end
  object edt_codigo: TEdit
    Left = 60
    Top = 13
    Width = 113
    Height = 21
    CharCase = ecUpperCase
    MaxLength = 13
    TabOrder = 0
  end
  object lkcmb_linea: TDBLookupComboBox
    Left = 583
    Top = 12
    Width = 110
    Height = 21
    DropDownWidth = 300
    KeyField = 'LINEA'
    ListField = 'LINEA; DESCRI'
    ListSource = dts_lineas
    TabOrder = 5
  end
  object lkcmb_grupo: TDBLookupComboBox
    Left = 60
    Top = 36
    Width = 113
    Height = 21
    DropDownWidth = 300
    KeyField = 'CODIGO'
    ListField = 'CODIGO; DESCRI'
    ListSource = dts_grupos
    TabOrder = 14
  end
  object lkcmb_prove: TDBLookupComboBox
    Left = 240
    Top = 36
    Width = 129
    Height = 21
    DropDownWidth = 300
    KeyField = 'CODIGO'
    ListField = 'CODIGO; NOMBRE'
    ListSource = dts_prove
    TabOrder = 4
  end
  object lkcmb_diary: TDBLookupComboBox
    Left = 410
    Top = 36
    Width = 117
    Height = 21
    DropDownWidth = 300
    KeyField = 'GRUPO'
    ListField = 'GRUPO; DESCRI'
    ListSource = dts_diary
    TabOrder = 13
  end
  object edt_alta: TEdit
    Left = 583
    Top = 35
    Width = 110
    Height = 21
    CharCase = ecUpperCase
    TabOrder = 17
  end
  object edt_costosi: TdxCurrencyEdit
    Left = 60
    Top = 59
    Width = 80
    TabOrder = 11
    OnExit = edt_costosiExit
  end
  object edt_costono: TdxCurrencyEdit
    Left = 60
    Top = 82
    Width = 80
    TabOrder = 12
  end
  object edt_preciomds: TdxCurrencyEdit
    Left = 208
    Top = 59
    Width = 80
    TabOrder = 9
  end
  object edt_precelec: TdxCurrencyEdit
    Left = 208
    Top = 83
    Width = 80
    Enabled = False
    TabOrder = 18
  end
  object edt_costocext: TdxCurrencyEdit
    Left = 60
    Top = 107
    Width = 80
    Enabled = False
    TabOrder = 19
  end
  object edt_prvtacext: TdxCurrencyEdit
    Left = 208
    Top = 107
    Width = 80
    Enabled = False
    TabOrder = 20
  end
  object edt_mubmds: TdxCurrencyEdit
    Left = 328
    Top = 59
    Width = 40
    Enabled = False
    TabOrder = 21
    DisplayFormat = ',0.00;-,0.00'
    StoredValues = 0
  end
  object edt_mubelec: TdxCurrencyEdit
    Left = 328
    Top = 83
    Width = 40
    Enabled = False
    TabOrder = 22
    DisplayFormat = ',0.00;-,0.00'
    StoredValues = 0
  end
  object edt_mubcext: TdxCurrencyEdit
    Left = 328
    Top = 107
    Width = 40
    Enabled = False
    TabOrder = 23
    DisplayFormat = ',0.00;-,0.00'
    StoredValues = 0
  end
  object edt_minimo: TdxCurrencyEdit
    Left = 411
    Top = 59
    Width = 30
    TabOrder = 7
    DecimalPlaces = 0
    DisplayFormat = ',0;-,0'
    StoredValues = 0
  end
  object edt_maximo: TdxCurrencyEdit
    Left = 411
    Top = 83
    Width = 30
    TabOrder = 8
    DecimalPlaces = 0
    DisplayFormat = ',0;-,0'
    StoredValues = 0
  end
  object edt_piva: TdxCurrencyEdit
    Left = 480
    Top = 83
    Width = 45
    TabOrder = 10
    DecimalPlaces = 0
    DisplayFormat = ',0;-,0'
    StoredValues = 0
  end
  object edt_plazo: TEdit
    Left = 479
    Top = 107
    Width = 46
    Height = 21
    CharCase = ecUpperCase
    TabOrder = 24
  end
  object lkcmb_situacion: TDBLookupComboBox
    Left = 583
    Top = 59
    Width = 110
    Height = 21
    DropDownWidth = 300
    KeyField = 'IDSITUAC'
    ListField = 'SITUACION'
    ListSource = dts_situaciones
    TabOrder = 6
  end
  object lkcmb_marcas: TDBLookupComboBox
    Left = 583
    Top = 83
    Width = 110
    Height = 21
    DropDownWidth = 300
    KeyField = 'CODIGO'
    ListField = 'CODIGO; MARCA'
    ListSource = dts_marcas
    TabOrder = 15
  end
  object lkcmb_garantia: TDBLookupComboBox
    Left = 583
    Top = 107
    Width = 110
    Height = 21
    DropDownWidth = 300
    KeyField = 'clave'
    ListField = 'clave; descri'
    ListSource = dts_garantia
    TabOrder = 16
  end
  object edt_descri2: TdxEdit
    Left = 59
    Top = 132
    Width = 466
    TabOrder = 2
    CharCase = ecUpperCase
    MaxLength = 70
    StoredValues = 2
  end
  object cmb_tipo: TComboBox
    Left = 480
    Top = 59
    Width = 45
    Height = 21
    Style = csDropDownList
    ItemHeight = 13
    TabOrder = 3
    Items.Strings = (
      'ALF'
      'GLO')
  end
  object edt_descri: TEdit
    Left = 240
    Top = 13
    Width = 286
    Height = 21
    CharCase = ecUpperCase
    MaxLength = 30
    TabOrder = 1
  end
  object grp_codsat: TGroupBox
    Left = 61
    Top = 158
    Width = 466
    Height = 99
    Caption = 'Código del Sat'
    TabOrder = 25
    object lbl_codsat: TLabel
      Left = 9
      Top = 49
      Width = 38
      Height = 13
      Caption = 'Cod.Sat'
    end
    object lkcmb_catsat: TDBLookupComboBox
      Left = 51
      Top = 46
      Width = 166
      Height = 21
      DropDownWidth = 300
      KeyField = 'CODIGO'
      ListField = 'CODIGO'
      ListSource = dts_catprodsat
      TabOrder = 2
    end
    object dbedt_codsat: TDBEdit
      Left = 52
      Top = 70
      Width = 298
      Height = 21
      TabStop = False
      DataField = 'DESCRI'
      DataSource = dts_catprodsat
      TabOrder = 3
    end
    object rbtn_catsatcod: TRadioButton
      Left = 144
      Top = 18
      Width = 113
      Height = 17
      Caption = 'del Artículo'
      TabOrder = 1
      OnClick = rbtn_catsatcodClick
    end
    object rbtn_catsatgpo: TRadioButton
      Left = 16
      Top = 18
      Width = 113
      Height = 17
      Caption = 'Del Grupo'
      Checked = True
      TabOrder = 0
      TabStop = True
      OnClick = rbtn_catsatcodClick
    end
  end
  object qry_diary: TQuery
    AutoRefresh = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select * from gpodiary where cia = :CIA order by grupo')
    Left = 656
    Top = 176
    ParamData = <
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object dts_diary: TDataSource
    DataSet = qry_diary
    Left = 656
    Top = 208
  end
  object qry_lineas: TQuery
    AutoRefresh = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select * from inv_lineas where status = '#39'A'#39
      'order by linea'
      ' ')
    Left = 688
    Top = 176
  end
  object dts_lineas: TDataSource
    DataSet = qry_lineas
    Left = 688
    Top = 208
  end
  object qry_grupos: TQuery
    AutoRefresh = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select * from inv_grupos where cia = :CIA order by codigo'
      ' ')
    Left = 624
    Top = 176
    ParamData = <
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object dts_grupos: TDataSource
    DataSet = qry_grupos
    Left = 624
    Top = 208
  end
  object qry_prove: TQuery
    AutoRefresh = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select codigo, nombre from proveedor where cia = :CIA order by c' +
        'odigo'
      '')
    Left = 592
    Top = 176
    ParamData = <
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object dts_prove: TDataSource
    DataSet = qry_prove
    Left = 592
    Top = 208
  end
  object qry_situaciones: TQuery
    AutoRefresh = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select * from inv_situaciones order by situacion'
      '')
    Left = 560
    Top = 176
  end
  object dts_situaciones: TDataSource
    DataSet = qry_situaciones
    Left = 560
    Top = 208
  end
  object qry_marcas: TQuery
    AutoRefresh = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select * from inv_marcas order by codigo'
      ''
      ' '
      ' ')
    Left = 528
    Top = 176
  end
  object dts_marcas: TDataSource
    DataSet = qry_marcas
    Left = 528
    Top = 208
  end
  object qry_garantia: TQuery
    AutoRefresh = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select * from inv_garantias where cia = :CIA order by meses, cla' +
        've'
      '')
    Left = 496
    Top = 176
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object dts_garantia: TDataSource
    DataSet = qry_garantia
    Left = 496
    Top = 208
  end
  object qry_inven: TQuery
    CachedUpdates = True
    AutoRefresh = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select'
      'codigo,cod2,descri,tipo,prove,linea,empaqe,minimo,maximo,'
      
        'precio,piva,costos,coston,inicials,entcoms,entcans,entesps,salvt' +
        'as,salfons,'
      
        'salesps,salmays,existes,inicialn,entcomn,entcann,entespn,salvtan' +
        ',salfonn,'
      
        'salespn,salmayn,existen,cosinicials,cosentcoms,cosentcans,cosent' +
        'esps,'
      
        'cossalvtas,cossalfons,cossalesps,cossalmays,cosexistes,cosinicia' +
        'ln,'
      
        'cosentcomn,cosentcann,cosentespn,cossalvtan,cossalfonn,cossalesp' +
        'n,'
      'cossalmayn,cosexisten,fecalta,cia,mds,elec,precelec'
      'from inven where codigo = :CODIGO and cia = :CIA'
      '')
    UpdateObject = uqry_inven
    Left = 464
    Top = 176
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
  object qry_invhist: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select'
      'idart,codigo,iddescri,cia'
      'from inv_invhist where codigo = :CODIGO and cia = :CIA'
      '')
    UpdateObject = uqry_invhist
    Left = 434
    Top = 176
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
      '  CODIGO = :CODIGO,'
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
      '  CIA = :CIA,'
      '  MDS = :MDS,'
      '  ELEC = :ELEC,'
      '  PRECELEC = :PRECELEC'
      'where'
      '  CODIGO = :OLD_CODIGO and'
      '  CIA = :OLD_CIA'
      ' ')
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
    Left = 463
    Top = 207
  end
  object uqry_invhist: TUpdateSQL
    ModifySQL.Strings = (
      'update inv_invhist'
      'set'
      '  IDART = :IDART,'
      '  CODIGO = :CODIGO,'
      '  IDDESCRI = :IDDESCRI,'
      '  CIA = :CIA'
      'where'
      '  IDART = :OLD_IDART')
    InsertSQL.Strings = (
      'insert into inv_invhist'
      '  (IDART, CODIGO, IDDESCRI, CIA)'
      'values'
      '  (:IDART, :CODIGO, :IDDESCRI, :CIA)')
    DeleteSQL.Strings = (
      'delete from inv_invhist'
      'where'
      '  IDART = :OLD_IDART')
    Left = 433
    Top = 207
  end
  object uqry_invrelinv: TUpdateSQL
    ModifySQL.Strings = (
      'update inv_relinv'
      'set'
      '  IDRELINV = :IDRELINV,'
      '  IDART = :IDART,'
      '  IDREL = :IDREL,'
      '  IDDATO = :IDDATO,'
      '  CONSE = :CONSE'
      'where'
      '  IDRELINV = :OLD_IDRELINV')
    InsertSQL.Strings = (
      'insert into inv_relinv'
      '  (IDRELINV, IDART, IDREL, IDDATO, CONSE)'
      'values'
      '  (:IDRELINV, :IDART, :IDREL, :IDDATO, :CONSE)')
    DeleteSQL.Strings = (
      'delete from inv_relinv'
      'where'
      '  IDRELINV = :OLD_IDRELINV')
    Left = 401
    Top = 207
  end
  object qry_invrelinv: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select'
      'idrelinv,idart,idrel,iddato,conse'
      'from inv_relinv where idart = :IDART')
    UpdateObject = uqry_invrelinv
    Left = 402
    Top = 176
    ParamData = <
      item
        DataType = ftInteger
        Name = 'IDART'
        ParamType = ptUnknown
      end>
  end
  object qry_buscasigid: TQuery
    AutoRefresh = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select * from inv_lineas where status = '#39'A'#39
      'order by linea'
      ' ')
    Left = 368
    Top = 176
  end
  object qry_catprodsat: TQuery
    AutoRefresh = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select * from inv_catprodsat where status = '#39'A'#39' order by descri'
      '')
    Left = 336
    Top = 176
  end
  object dts_catprodsat: TDataSource
    DataSet = qry_catprodsat
    Left = 336
    Top = 208
  end
end
