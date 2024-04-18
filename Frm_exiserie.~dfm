object Form_exiserie: TForm_exiserie
  Left = 286
  Top = 290
  Width = 698
  Height = 267
  Caption = 'Existencia Mercancias con Series'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poDefault
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 682
    Height = 217
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object btn_imprel: TBitBtn
      Left = 62
      Top = 150
      Width = 77
      Height = 25
      Action = imprimir_reporte
      Caption = 'Reporte'
      TabOrder = 5
      Glyph.Data = {
        36040000424D3604000000000000360000002800000010000000100000000100
        2000000000000004000000000000000000000000000000000000FF00FF000000
        0000000000000000000000000000000000000000000000000000000000000000
        00000000000000000000000000000000000000000000FF00FF0000000000BFBF
        BF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBF
        BF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF000000000000000000BFBF
        BF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBF
        BF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF0000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        000000000000000000000000000000000000000000000000000000000000FFFF
        FF00BFBFBF00FFFFFF00BFBFBF00FFFFFF00BFBFBF00FFFFFF00BFBFBF00FFFF
        FF00BFBFBF00FFFFFF00BFBFBF00FFFFFF00BFBFBF000000000000000000BFBF
        BF00FFFFFF00BFBFBF00FFFFFF00BFBFBF00FFFFFF00BFBFBF00FFFFFF00BFBF
        BF00FFFFFF00BFBFBF00FFFFFF000000FF00FFFFFF000000000000000000FFFF
        FF00BFBFBF00FFFFFF00BFBFBF00FFFFFF00BFBFBF00FFFFFF00BFBFBF00FFFF
        FF00BFBFBF00FFFFFF00BFBFBF00FFFFFF00BFBFBF0000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000FF00FF00FF00
        FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF0000000000000000000000000000000000FFFF
        FF0000000000FFFFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
        FF00FFFFFF00FFFFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF000000000000000000FFFFFF00000000000000
        0000000000000000000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FFFF
        FF00FFFFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF0000000000BFBFBF00FFFFFF0000000000FFFF
        FF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
        0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
        FF00FF00FF00000000000000000000000000000000000000000000000000FF00
        FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00}
    end
    object pnl_datos: TGroupBox
      Left = 12
      Top = 9
      Width = 200
      Height = 136
      Caption = 'Fecha Corte:'
      TabOrder = 0
      object lbl_vigencia: TLabel
        Left = 5
        Top = 21
        Width = 63
        Height = 13
        Caption = 'Fecha Inicial:'
      end
      object Label3: TLabel
        Left = 25
        Top = 45
        Width = 41
        Height = 13
        Caption = 'Vigencia'
        Visible = False
      end
      object date_ini: TDateTimePicker
        Left = 71
        Top = 17
        Width = 90
        Height = 21
        CalAlignment = dtaLeft
        Date = 38762.7111857986
        Time = 38762.7111857986
        DateFormat = dfShort
        DateMode = dmComboBox
        Kind = dtkDate
        ParseInput = False
        TabOrder = 0
        OnExit = date_iniExit
      end
      object date_vigencia: TDateTimePicker
        Left = 71
        Top = 41
        Width = 90
        Height = 21
        CalAlignment = dtaLeft
        Date = 38762.7111857986
        Time = 38762.7111857986
        DateFormat = dfShort
        DateMode = dmComboBox
        Enabled = False
        Kind = dtkDate
        ParseInput = False
        TabOrder = 1
        Visible = False
      end
    end
    object GroupBox5: TGroupBox
      Left = 420
      Top = 94
      Width = 200
      Height = 50
      Caption = 'Imprimo Costo ?'
      TabOrder = 4
      object rbtn_concosto: TRadioButton
        Left = 8
        Top = 16
        Width = 81
        Height = 16
        Caption = 'Sí'
        TabOrder = 0
      end
      object rbtn_sincosto: TRadioButton
        Left = 91
        Top = 18
        Width = 94
        Height = 16
        Caption = 'No'
        Checked = True
        TabOrder = 1
        TabStop = True
      end
    end
    object GroupBox2: TGroupBox
      Left = 219
      Top = 9
      Width = 200
      Height = 80
      TabOrder = 1
      object Label1: TLabel
        Left = 11
        Top = 22
        Width = 41
        Height = 13
        Caption = 'Almacen'
      end
      object edt_almini: TEdit
        Left = 65
        Top = 18
        Width = 49
        Height = 21
        CharCase = ecUpperCase
        TabOrder = 0
        OnChange = edt_alminiExit
        OnExit = edt_alminiExit
      end
      object chk_impriserie: TCheckBox
        Left = 16
        Top = 48
        Width = 97
        Height = 17
        Caption = 'Conteo P/Almacén'
        TabOrder = 1
      end
    end
    object GroupBox4: TGroupBox
      Left = 219
      Top = 94
      Width = 200
      Height = 50
      Caption = 'Existencias de mercancía:'
      TabOrder = 3
      object rbtn_exisi: TRadioButton
        Left = 12
        Top = 21
        Width = 41
        Height = 17
        Caption = 'SI'
        TabOrder = 0
      end
      object rbtn_exino: TRadioButton
        Left = 50
        Top = 21
        Width = 49
        Height = 17
        Caption = 'NO'
        TabOrder = 1
      end
      object rbtn_exitot: TRadioButton
        Left = 106
        Top = 21
        Width = 49
        Height = 17
        Caption = 'Global'
        Checked = True
        TabOrder = 2
        TabStop = True
      end
    end
    object GroupBox3: TGroupBox
      Left = 420
      Top = 9
      Width = 200
      Height = 80
      Caption = 'Lineas:'
      TabOrder = 2
      object Label2: TLabel
        Left = 11
        Top = 22
        Width = 27
        Height = 13
        Caption = 'Inicial'
      end
      object Label4: TLabel
        Left = 112
        Top = 21
        Width = 22
        Height = 13
        Caption = 'Final'
      end
      object edt_lineaini: TEdit
        Left = 57
        Top = 18
        Width = 50
        Height = 21
        CharCase = ecUpperCase
        TabOrder = 0
      end
      object edt_lineafin: TEdit
        Left = 138
        Top = 18
        Width = 50
        Height = 21
        CharCase = ecUpperCase
        TabOrder = 1
      end
    end
  end
  object qry_almacen: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select a.clave,a.nombre, a.cia,a.exib,a.zona, b.nombre as nomzon' +
        ' from almacen a join zonainv b on a.zona = b.zona where '
      
        'clave between :ALMINI and :ALMFIN and cia= :CIA order by zona,cl' +
        'ave')
    Left = 8
    Top = 192
    ParamData = <
      item
        DataType = ftString
        Name = 'ALMINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'ALMFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'Cia'
        ParamType = ptUnknown
      end>
  end
  object qry_exisi: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select b.orden, a.linea, a.tipo, a.codigo, a.descri, a.empaqe, a' +
        '.piva, a.precio,'
      
        '  a.costos, a.fecalta, salvtas+salvtan+salfons+salfonn as univta' +
        ','
      '  salmays + salmayn as salmay,'
      'count(*) as unidexis'
      
        'from inven a join inv_lineas b on a.linea = b.linea and a.cia = ' +
        'b.cia'
      'join movart c on a.codigo = c.codigo and a.cia = c.cia'
      'where a.linea between :PRLINEA and :ULLINEA and a.cia= :CIA'
      'and'
      '( c.modent = :MODENT1 or c.modent = :MODENT2 )'
      
        'and (salio<>'#39'S'#39' or (salio='#39'S'#39' and fechasal > :FECORTE )) and alm' +
        'ac = :ALM'
      #9'and fecha <= :FECORTE'
      'group by b.orden, a.linea,a.tipo, a.codigo,a.descri,'
      'a.empaqe,a.piva,a.precio,a.costos,'
      'a.fecalta, univta, salmay'
      'order by a.linea,b.orden,a.codigo'
      '')
    Left = 48
    Top = 192
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'PRLINEA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'ULLINEA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'MODENT1'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'MODENT2'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'FECORTE'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'ALM'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'FECORTE'
        ParamType = ptUnknown
      end>
  end
  object qry_lineas: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select * from inv_lineas where linea = :LINEA and cia = :CIA'
      '')
    Left = 168
    Top = 192
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'LINEA'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qry_costlinea: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select sum(costosi+costono) as total,(select sum(costosi+costono' +
        ') from resulcosinv where'
      #9'fecha= :FECHA'
      
        ' and zona= :ZONA and (entcan= :ENTCAN  or entcan= :NOCAN) and li' +
        'nea= :LINEA and cia= :CIA) as totzona from resulcosinv where'
      
        #9'fecha= :FECHA and alm= :ALM and (entcan= :ENTCAN  or entcan= :N' +
        'OCAN) and linea= :LINEA and cia= :CIA')
    Left = 198
    Top = 160
    ParamData = <
      item
        DataType = ftDateTime
        Name = 'FECHA'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'ZONA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'ENTCAN'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'NOCAN'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'LINEA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECHA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'ALM'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'ENTCAN'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'NOCAN'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'LINEA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qry_almzona: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select a.clave,a.nombre, a.cia,a.exib,a.zona, b.nombre as nomzon' +
        ' from almacen a join zonainv b on a.zona = b.zona where '
      
        'clave between :ALMINI and :ALMFIN and cia= :CIA and b.zona = :ZO' +
        'NA order by zona,clave')
    Left = 136
    Top = 184
    ParamData = <
      item
        DataType = ftString
        Name = 'ALMINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'ALMFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'ZONA'
        ParamType = ptUnknown
      end>
  end
  object qry_zonas: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select * from zonainv order by tipo')
    Left = 103
    Top = 176
  end
  object qry_armzon: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select a.clave,a.nombre from almacen a join zonainv b on a.zona ' +
        '= b.zona where clave between :ALMINI and :ALMFIN and cia= :CIA '
      'and b.zona = :ZONA order by clave')
    Left = 165
    Top = 88
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'ALMINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'ALMFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'ZONA'
        ParamType = ptUnknown
      end>
  end
  object qry_costzon: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select sum(costosi+costono) as tot1,( select sum(costosi+costono' +
        ') from resulcosinv where'
      
        #9'fecha= :FECHA and (entcan= :ENTCAN or entcan= :NOCAN) and linea' +
        '= :LINEA and cia= :CIA) as tot2 from resulcosinv where  zona = :' +
        'ZON and'
      
        #9'fecha= :FECHA and (entcan= :ENTCAN or entcan= :NOCAN) and linea' +
        '= :LINEA and cia= :CIA')
    Left = 262
    Top = 120
    ParamData = <
      item
        DataType = ftDateTime
        Name = 'FECHA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'ENTCAN'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'NOCAN'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'LINEA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'ZON'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECHA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'ENTCAN'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'NOCAN'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'LINEA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qry_series: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select costo,serie,fecha as fecmov from movart'
      'where codigo= :CODIGO and almac = :ALM'
      'and fecha <= :FECORTE and cia= :CIA'
      'and (modent= :MODENT1 or modent = :MODENT2 ) and'
      '(salio<>'#39'S'#39' or (salio='#39'S'#39' and fechasal > :FECORTE))'
      'order by folio,fecha,serie'
      ''
      ' ')
    Left = 231
    Top = 174
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'ALM'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'FECORTE'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'MODENT1'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'MODENT2'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'FECORTE'
        ParamType = ptUnknown
      end>
  end
  object qry_desglose: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select sum(costosi) as costosi,(select sum(costono) from resulco' +
        'sinv'
      
        #9'where fecha= :FECHA and linea= :LINEA and (entcan= :ENTCAN or e' +
        'ntcan= :NOCAN) and cia= :CIA) as costono from resulcosinv'
      
        #9'where fecha= :FECHA and linea= :LINEA and (entcan= :ENTCAN or e' +
        'ntcan= :NOCAN) and cia= :CIA')
    Left = 424
    Top = 120
    ParamData = <
      item
        DataType = ftDateTime
        Name = 'FECHA'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'LINEA'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'ENTCAN'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'NOCAN'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECHA'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'LINEA'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'ENTCAN'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'NOCAN'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qry_gendesg: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select sum(costosi) as costosi,(select sum(costono) from resulco' +
        'sinv'
      
        #9'where fecha= :FECHA  and (entcan= :ENTCAN or entcan= :NOCAN) an' +
        'd cia= :CIA) as costono from resulcosinv'
      
        #9'where fecha= :FECHA  and (entcan= :ENTCAN or entcan= :NOCAN) an' +
        'd cia= :CIA')
    Left = 463
    Top = 120
    ParamData = <
      item
        DataType = ftDateTime
        Name = 'FECHA'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'ENTCAN'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'NOCAN'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECHA'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'ENTCAN'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'NOCAN'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object ActionList1: TActionList
    Images = dm.ImageList1
    Left = 584
    Top = 112
    object imprimir_reporte: TAction
      Caption = 'Reporte'
      ImageIndex = 21
      OnExecute = imprimir_reporteExecute
    end
  end
  object qry_fecorte: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select * from inv_corteanu'
      'where cia = :CIA')
    Left = 495
    Top = 120
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qry_articulosglo: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select sum(costo) as costo, min(fecha) as fecmov'
      'from movart'
      'where codigo= :CODIGO and almac = :ALM'
      'and fecha <= :FECORTE and cia= :CIA'
      'and (modent= :MODENT1 or modent = :MODENT2 ) and'
      '(salio<>'#39'S'#39' or (salio='#39'S'#39' and fechasal > :FECORTE))'
      '')
    Left = 263
    Top = 174
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'CODIGO'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'ALM'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'FECORTE'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'MODENT1'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'MODENT2'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'FECORTE'
        ParamType = ptUnknown
      end>
  end
end
