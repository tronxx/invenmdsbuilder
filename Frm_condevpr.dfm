object Form_condevpr: TForm_condevpr
  Left = 246
  Top = 165
  Width = 701
  Height = 270
  Caption = ' Concentrado de Devolucion de Proveedor'
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
    Width = 693
    Height = 89
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object btn_imprel: TBitBtn
      Left = 598
      Top = 32
      Width = 77
      Height = 23
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
      Left = 8
      Top = 1
      Width = 193
      Height = 80
      Caption = 'Fecha:'
      TabOrder = 2
      object lbl_vigencia: TLabel
        Left = 6
        Top = 18
        Width = 63
        Height = 13
        Caption = 'Fecha Inicial:'
      end
      object lbl_corte: TLabel
        Left = 7
        Top = 46
        Width = 58
        Height = 13
        Caption = 'Fecha Final:'
      end
      object date_ini: TDateTimePicker
        Left = 69
        Top = 14
        Width = 90
        Height = 22
        CalAlignment = dtaLeft
        Date = 38762.7111857986
        Time = 38762.7111857986
        DateFormat = dfShort
        DateMode = dmComboBox
        Kind = dtkDate
        ParseInput = False
        TabOrder = 0
      end
      object date_fin: TDateTimePicker
        Left = 69
        Top = 41
        Width = 92
        Height = 22
        CalAlignment = dtaLeft
        Date = 38982.3491966782
        Time = 38982.3491966782
        DateFormat = dfShort
        DateMode = dmComboBox
        Kind = dtkDate
        ParseInput = False
        TabOrder = 1
      end
    end
    object GroupBox3: TGroupBox
      Left = 208
      Top = 1
      Width = 162
      Height = 80
      Caption = 'Proveedoress:'
      TabOrder = 1
      object Label1: TLabel
        Left = 7
        Top = 20
        Width = 71
        Height = 13
        Caption = 'Del Proveedor:'
      end
      object Label3: TLabel
        Left = 13
        Top = 42
        Width = 64
        Height = 13
        Caption = 'Al Proveedor:'
      end
      object edt_pini: TEdit
        Left = 81
        Top = 15
        Width = 44
        Height = 21
        CharCase = ecUpperCase
        TabOrder = 0
      end
      object edt_pfin: TEdit
        Left = 81
        Top = 39
        Width = 44
        Height = 21
        CharCase = ecUpperCase
        TabOrder = 1
        Text = 'ZZ'
      end
    end
    object GroupBox5: TGroupBox
      Left = 377
      Top = 1
      Width = 192
      Height = 40
      Caption = 'Reporte De Almacen Y Linea:'
      TabOrder = 3
      object rbtn_ralmsi: TRadioButton
        Left = 32
        Top = 18
        Width = 73
        Height = 17
        Caption = 'SI'
        Checked = True
        TabOrder = 0
        TabStop = True
      end
      object rbtn_ralmno: TRadioButton
        Left = 112
        Top = 18
        Width = 62
        Height = 17
        Caption = 'NO'
        TabOrder = 1
      end
    end
    object GroupBox1: TGroupBox
      Left = 377
      Top = 41
      Width = 192
      Height = 40
      Caption = 'Reporte Con Costos Financieros:'
      TabOrder = 4
      object rbtn_rcostosi: TRadioButton
        Left = 32
        Top = 18
        Width = 73
        Height = 17
        Caption = 'SI'
        Checked = True
        TabOrder = 0
        TabStop = True
      end
      object rbtn_rcostono: TRadioButton
        Left = 112
        Top = 18
        Width = 62
        Height = 17
        Caption = 'NO'
        TabOrder = 1
      end
    end
  end
  object qry_compra: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      
        'select sum(importe+iva) as si from entradas where tipo= :TPENT a' +
        'nd prove= :PROVE'
      
        #9'and fecha between :FECINI and :FECFIN and coniva= :SINO and cia' +
        '= :CIA'
      '')
    Left = 88
    Top = 272
    ParamData = <
      item
        DataType = ftString
        Name = 'TPENT'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'PROVE'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'SINO'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qry_almacen: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      
        'select a.alm,b.nombre,a.fecha,a.numero,a.prove,c.nombre as nompr' +
        'ove from entradas a join almacen b on b.clave = a.alm'
      'join proveedor c on c.codigo = a.prove'
      
        'where a.tipo= :TPDEV and fecha between :FECINI and :FECFIN and p' +
        'rove between :PINI and :PFIN'
      'and a.cia= :CIA order by alm,numero')
    Left = 584
    Top = 1
    ParamData = <
      item
        DataType = ftString
        Name = 'TPDEV'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'PINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'PFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qry_datos: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      
        'select a.codinv,b.descri,a.serie,a.folsal,a.costou,a.siono,a.ent' +
        'can,(a.costou*a.piva/100) as tot from renentra a join inven b  o' +
        'n b.codigo = codinv '
      'where a.tipo= :TPDEV and a.numero = :NUM')
    Left = 619
    Top = 1
    ParamData = <
      item
        DataType = ftString
        Name = 'TPDEV'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'NUM'
        ParamType = ptUnknown
      end>
  end
  object qry_lineas: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select unique c.linea,d.descri as des, c.codigo,c.descri'
      
        '        from entradas a join renentra b on a.tipo = b.tipo and a' +
        '.alm = b.alm '
      '        and a.numero = b.numero and a.cia = b.cia'
      '        join inven c on b.codinv = c.codigo and b.cia = c.cia'
      '        join lineas d on c.linea = d.numero '
      
        '        where a.tipo= :TPDEV and a.fecha between :FECINI and :FE' +
        'CFIN '
      '        and a.prove between :PINI and :PFIN and a.cia = :CIA'
      '        order by d.orden,c.linea,c.codigo,b.entosal')
    Left = 656
    Top = 1
    ParamData = <
      item
        DataType = ftString
        Name = 'TPDEV'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'PINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'PFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qry_cantline: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select count(*) as unid,sum(b.importe) as import,'
      #9'sum(b.importe*b.piva/100) as tot from'
      
        #9'entradas a join renentra b on a.tipo=b.tipo and a.numero=b.nume' +
        'ro'
      '        and a.alm=b.alm and a.cia=b.cia'
      '        where'
      
        #9'a.tipo= :TPDEV and a.fecha between :FECINI and :FECFIN  and a.p' +
        'rove between :PINI and :PFIN'
      '        and b.codinv= :CODINV and a.cia= :CIA')
    Left = 594
    Top = 57
    ParamData = <
      item
        DataType = ftString
        Name = 'TPDEV'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'PINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'PFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'CODINV'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qry_financ: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select alm, numero, prove, fecha, importe, iva, ctofin, total'
      
        #9'from entradas where tipo = :TPDEV and fecha between :FECINI and' +
        ' :FECFIN '
      '        and prove between :PINI and :PFIN and cia= :CIA'
      '        and status = '#39'C'#39' order by alm, numero')
    Left = 636
    Top = 57
    ParamData = <
      item
        DataType = ftString
        Name = 'TPDEV'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'PINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'PFIN'
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
    Left = 448
    Top = 112
    object imprimir_reporte: TAction
      Caption = 'Reporte'
      ImageIndex = 21
      OnExecute = imprimir_reporteExecute
    end
  end
end
