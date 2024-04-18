object Form_exican: TForm_exican
  Left = 286
  Top = 290
  Width = 698
  Height = 192
  Caption = 'Existencia Mercancia Cancelada'
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
    Width = 690
    Height = 153
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object btn_imprel: TBitBtn
      Left = 318
      Top = 118
      Width = 77
      Height = 25
      Action = imprimir_reporte
      Caption = 'Reporte'
      TabOrder = 0
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
      Height = 48
      Caption = 'Fecha Corte:'
      TabOrder = 1
      object lbl_vigencia: TLabel
        Left = 5
        Top = 21
        Width = 63
        Height = 13
        Caption = 'Fecha Inicial:'
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
      end
    end
    object GroupBox5: TGroupBox
      Left = 428
      Top = 62
      Width = 250
      Height = 50
      Caption = 'Imprimo Exixtencias de Mercancias:'
      TabOrder = 4
      object rbtn_cancelados: TRadioButton
        Left = 8
        Top = 16
        Width = 113
        Height = 16
        Caption = 'Canceladas '
        Checked = True
        TabOrder = 0
        TabStop = True
      end
      object rbtn_nocancel: TRadioButton
        Left = 91
        Top = 18
        Width = 94
        Height = 16
        Caption = 'NO Cancelada'
        TabOrder = 1
      end
      object rbtn_todos: TRadioButton
        Left = 191
        Top = 19
        Width = 52
        Height = 16
        Caption = 'Todos'
        TabOrder = 2
      end
    end
    object GroupBox2: TGroupBox
      Left = 219
      Top = 9
      Width = 200
      Height = 49
      Caption = 'Almacenes:'
      TabOrder = 2
      object Label1: TLabel
        Left = 11
        Top = 22
        Width = 22
        Height = 13
        Caption = 'Del: '
      end
      object Label3: TLabel
        Left = 123
        Top = 21
        Width = 12
        Height = 13
        Caption = 'Al:'
      end
      object edt_almini: TEdit
        Left = 33
        Top = 18
        Width = 49
        Height = 21
        CharCase = ecUpperCase
        TabOrder = 0
      end
      object edt_almfin: TEdit
        Left = 138
        Top = 18
        Width = 49
        Height = 21
        CharCase = ecUpperCase
        TabOrder = 1
      end
    end
    object GroupBox3: TGroupBox
      Left = 428
      Top = 8
      Width = 250
      Height = 50
      Caption = 'Deseas Tabla - Linea - Almacen'
      TabOrder = 3
      object rbtn_lasi: TRadioButton
        Left = 47
        Top = 21
        Width = 41
        Height = 17
        Caption = 'SI'
        Checked = True
        TabOrder = 0
        TabStop = True
      end
      object rbtn_lano: TRadioButton
        Left = 90
        Top = 21
        Width = 49
        Height = 17
        Caption = 'NO'
        TabOrder = 1
      end
    end
    object GroupBox1: TGroupBox
      Left = 9
      Top = 63
      Width = 200
      Height = 50
      Caption = 'Deseas Tabla - Linea - Zona'
      TabOrder = 5
      object rbtn_lzsi: TRadioButton
        Left = 47
        Top = 21
        Width = 41
        Height = 17
        Caption = 'SI'
        Checked = True
        TabOrder = 0
        TabStop = True
      end
      object rbtn_lzno: TRadioButton
        Left = 90
        Top = 21
        Width = 49
        Height = 17
        Caption = 'NO'
        TabOrder = 1
      end
    end
    object GroupBox4: TGroupBox
      Left = 219
      Top = 63
      Width = 200
      Height = 50
      Caption = 'Deseas Tabla - Linea - Global'
      TabOrder = 6
      object rbtn_lgsi: TRadioButton
        Left = 47
        Top = 21
        Width = 41
        Height = 17
        Caption = 'SI'
        Checked = True
        TabOrder = 0
        TabStop = True
      end
      object rbtn_lgno: TRadioButton
        Left = 90
        Top = 21
        Width = 49
        Height = 17
        Caption = 'NO'
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
    Top = 120
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
      
        'select sum(costosi) as costosi,(select sum(costono) from resulco' +
        'sinv'
      
        #9'where fecha= :FECHA and alm= :ALM and (entcan= :ENTCAN or entca' +
        'n= :NOCAN) and cia= :CIA) as costono from resulcosinv'
      
        #9'where fecha= :FECHA and alm= :ALM and (entcan= :ENTCAN or entca' +
        'n= :NOCAN) and cia= :CIA'
      '')
    Left = 48
    Top = 120
    ParamData = <
      item
        DataType = ftUnknown
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
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
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
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qry_lineas: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select unique resulcosinv.linea,lineas.descri,lineas.orden,linea' +
        's.region'
      #9'from lineas,resulcosinv'
      
        #9'where resulcosinv.linea=lineas.numero and resulcosinv.fecha= :F' +
        'ECHA'
      
        #9'and (resulcosinv.entcan = :ENTCAN or resulcosinv.entcan= :NOCAN' +
        ')'
      '        and resulcosinv.cia= :CIA'
      #9'order by lineas.orden,lineas.numero'
      '')
    Left = 168
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
    Left = 206
    Top = 120
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
    Top = 120
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
    Top = 120
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
  object qry_zon: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select * from zonainv order by tipo')
    Left = 231
    Top = 86
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
end
