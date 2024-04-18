object Form_analimvm: TForm_analimvm
  Left = 288
  Top = 290
  Width = 698
  Height = 305
  Caption = 'Analítico de Movimientos/Vencimientos de Mayoreo'
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
    Height = 257
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
      TabOrder = 6
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
      Height = 100
      Caption = 'Fecha Corte:'
      TabOrder = 0
      object lbl_vigencia: TLabel
        Left = 5
        Top = 45
        Width = 55
        Height = 13
        Caption = 'Fecha Final'
      end
      object Label3: TLabel
        Left = 7
        Top = 21
        Width = 58
        Height = 13
        Caption = 'Fecha Inicio'
      end
      object date_corte: TDateTimePicker
        Left = 71
        Top = 41
        Width = 90
        Height = 21
        CalAlignment = dtaLeft
        Date = 38762.7111857986
        Time = 38762.7111857986
        DateFormat = dfShort
        DateMode = dmComboBox
        Kind = dtkDate
        ParseInput = False
        TabOrder = 1
      end
      object date_fecini: TDateTimePicker
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
        OnExit = date_feciniExit
      end
    end
    object GroupBox5: TGroupBox
      Left = 220
      Top = 113
      Width = 200
      Height = 50
      Caption = 'Imprimo Precio de Mayoreo ?'
      TabOrder = 4
      Visible = False
      object rbtn_sipreciomay: TRadioButton
        Left = 8
        Top = 16
        Width = 81
        Height = 16
        Caption = 'Sí'
        Checked = True
        TabOrder = 0
        TabStop = True
      end
      object rbtn_nopreciomay: TRadioButton
        Left = 91
        Top = 18
        Width = 94
        Height = 16
        Caption = 'No'
        TabOrder = 1
      end
    end
    object GroupBox2: TGroupBox
      Left = 219
      Top = 185
      Width = 200
      Height = 49
      TabOrder = 1
      Visible = False
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
      end
    end
    object GroupBox1: TGroupBox
      Left = 220
      Top = 9
      Width = 200
      Height = 100
      Caption = 'Reporte de :'
      TabOrder = 5
      object chk_analiabonos: TCheckBox
        Left = 8
        Top = 16
        Width = 169
        Height = 17
        Caption = 'Analítico de Abonos'
        TabOrder = 0
      end
      object chk_relvigtes: TCheckBox
        Left = 8
        Top = 46
        Width = 169
        Height = 17
        Caption = 'Pagarés Vigentes'
        TabOrder = 2
      end
      object chk_edores: TCheckBox
        Left = 8
        Top = 62
        Width = 169
        Height = 17
        Caption = 'Estado de Resultados'
        TabOrder = 3
      end
      object chk_mubmay: TCheckBox
        Left = 8
        Top = 78
        Width = 169
        Height = 17
        Caption = 'MUB Mayoreo'
        TabOrder = 4
      end
      object chk_analicargos: TCheckBox
        Left = 8
        Top = 31
        Width = 169
        Height = 17
        Caption = 'Analítico de Cargos'
        TabOrder = 1
      end
    end
    object GroupBox4: TGroupBox
      Left = 423
      Top = 113
      Width = 200
      Height = 50
      Caption = 'Existencias de mercancía:'
      TabOrder = 2
      Visible = False
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
      Left = 10
      Top = 113
      Width = 200
      Height = 50
      Caption = 'Mayoristas:'
      TabOrder = 3
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
      object edt_mayoini: TEdit
        Left = 57
        Top = 18
        Width = 50
        Height = 21
        CharCase = ecUpperCase
        TabOrder = 0
      end
      object edt_mayofin: TEdit
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
    Left = 48
    Top = 224
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
      
        'select b.orden, a.linea, a.codigo, a.descri, a.empaqe, a.piva, a' +
        '.precio,'
      
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
      'group by b.orden, a.linea,a.codigo,a.descri,'
      'a.empaqe,a.piva,a.precio,a.costos,'
      'a.fecalta, univta, salmay'
      'order by orden,a.linea,a.codigo'
      ''
      ''
      ' '
      ' '
      ' ')
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
  object qry_updtedomay: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select * from edomay '
      'where mayoris = :MAYORIS and fecha = :FECHA and cia = :CIA'
      ' '
      ' ')
    UpdateObject = uqry_updtedomay
    Left = 392
    Top = 175
    ParamData = <
      item
        DataType = ftString
        Name = 'MAYORIS'
        ParamType = ptUnknown
      end
      item
        DataType = ftDate
        Name = 'FECHA'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qry_mubmay: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select a.mayoris, a.cia,'
      'sum(a.total - a.iva) as totfac,'
      '( select sum(b.importe)'
      '  from entradas b where b.prove = a.mayoris and b.cia = a.cia'
      '  and b.tipo = '#39'M'#39' and b.fecha between :FECINI and :FECFIN'
      ') as salmay,'
      '('
      '  select sum(importe/1.16) as ncreneto'
      '  from movmay2 c where c.fecha between :FECINI and :FECFIN'
      
        '  and c.mayoris = a.mayoris and c.coa='#39'A'#39' and c.tipago='#39'N'#39' and c' +
        '.cia= a.cia'
      ') as ncredsiniva'
      'from facturma a'
      'where fecha between :FECINI and :FECFIN and a.cia = :CIA'
      'and a.tipofac = :TIPO_FAC_MAY and tipago = '#39'M'#39' and mayomen = '#39'Y'#39
      'group by a.mayoris, a.cia'
      ''
      ' '
      ' ')
    Left = 297
    Top = 174
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'FECINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'FECFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'FECINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'FECFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'FECINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'FECFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'TIPO_FAC_MAY'
        ParamType = ptUnknown
      end>
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
  object qry_edomay: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select a.mayoris,a.cia,'
      '( '
      '  select sum(b.sdofin) from edomay b where a.mayoris = b.mayoris'
      '  and a.cia = b.cia and b.fecha = :CORTEANTER'
      ')'
      'as sdoant,'
      'sum(a.compras) as comp,'
      'sum(a.abonos) as abon,'
      'sum(a.devols) as devs,'
      'sum(a.bonif) as bon,'
      'sum(a.sdofin) as sdo'
      'from edomay a'
      'where a.fecha = :FECORTE and a.cia = :CIA'
      'group by a.mayoris, a.cia'
      ''
      ' '
      ' '
      ' ')
    Left = 231
    Top = 174
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'CORTEANTER'
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
      end>
  end
  object qry_mayoristas: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select mayoris'
      'from movmay2 where'
      'mayoris between :PRMAYO and :ULMAYO and coa = '#39'C'#39
      'and fecha <= :FECORTE '
      'and ( saldo > 0.5 or ( saldo < 0.5 and fecsal > :FECORTE ) )'
      'and cia = :CIA'
      'group by mayoris'
      ' '
      ' '
      ' ')
    Left = 424
    Top = 120
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'PRMAYO'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'ULMAYO'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'FECORTE'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'FECORTE'
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
  object qry_perioxmay: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    SQL.Strings = (
      'select mayoris,'
      'extract(YEAR  from vence) as anu,'
      'extract(month from vence) as mes,'
      'sum(0) as saldo'
      'from movmay2 where'
      'mayoris = :MAYORIS and coa = '#39'C'#39
      'and fecha <= :FECORTE'
      'and ( saldo > 0.5 or ( saldo < 0.5 and fecsal > :FECORTE ) )'
      'and cia = :CIA'
      'group by mayoris, anu, mes'
      ''
      ' '
      ' '
      ' ')
    UpdateObject = uqry_perioxmay
    Left = 456
    Top = 120
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'MAYORIS'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'FECORTE'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'FECORTE'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qry_doctospend: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select a.mayoris, a.docto, a.pagare, a.importe, a.concep, a.tipa' +
        'go, a.vence, a.fecha, a.tipofac,'
      'a.cia,'
      '('
      
        '  select sum(b.importe) from movmay2 b where b.mayoris = a.mayor' +
        'is and b.docto = a.docto and b.tipofac = a.tipofac'
      
        '  and b.pagare = a.pagare and b.cia = a.cia and b.coa = '#39'A'#39' and ' +
        'b.fecha <= :FECORTE'
      ') as abonos'
      'from movmay2 a where'
      'a.mayoris = :MAYORIS and a.coa = '#39'C'#39
      'and a.fecha <= :FECORTE'
      
        'and ( a.saldo > 0.5 or ( a.saldo < 0.5 and a.fecsal > :FECORTE )' +
        ' )'
      'and a.cia = :CIA'
      'group by a.mayoris, a.docto, a.pagare,'
      
        'a.importe, a.concep, a.tipago, a.vence, a.fecha, a.tipofac, a.ci' +
        'a'
      ''
      ' '
      ' ')
    Left = 488
    Top = 120
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'FECORTE'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'MAYORIS'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'FECORTE'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'FECORTE'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object uqry_perioxmay: TUpdateSQL
    Left = 456
    Top = 152
  end
  object qry_abonos: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select a.mayoris, a.docto, a.pagare, a.fecha, a.tipago, a.concep' +
        ', a.importe,'
      '( select max(b.vence) from movmay2 b where b.mayoris = a.mayoris'
      'and b.docto = a.docto and b.pagare = b.pagare and b.cia = a.cia'
      'and b.coa = '#39'C'#39
      ') as vence,'
      '( select max(b.fecha) from movmay2 b where b.mayoris = a.mayoris'
      'and b.docto = a.docto and b.pagare = b.pagare and b.cia = a.cia'
      'and b.coa = '#39'C'#39
      ') as fechafac'
      ''
      'from movmay2 a'
      'where a.mayoris between  :PRMAYO and :ULMAYO'
      'and a.fecha between :FECINI and :FECFIN'
      'and a.coa='#39'A'#39' and a.cia = :CIA'
      'order by a.mayoris, a.docto, a.pagare,'
      'a.fecha, a.tipago, a.concep'
      ''
      '')
    Left = 328
    Top = 175
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'PRMAYO'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'ULMAYO'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'FECINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'FECFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object uqry_updtedomay: TUpdateSQL
    ModifySQL.Strings = (
      'update edomay'
      'set'
      '  COMPRAS = :COMPRAS,'
      '  ABONOS = :ABONOS,'
      '  DEVOLS = :DEVOLS,'
      '  SDOFIN = :SDOFIN,'
      '  BONIF = :BONIF,'
      '  VENCANT = :VENCANT,'
      '  VENCREC = :VENCREC,'
      '  PORVENC = :PORVENC,'
      '  COBINTERNA = :COBINTERNA,'
      '  CARTERA = :CARTERA'
      'where'
      '  FECHA = :OLD_FECHA and'
      '  CIA = :OLD_CIA and'
      '  MAYORIS = :OLD_MAYORIS')
    InsertSQL.Strings = (
      'insert into edomay'
      
        '  (FECHA, COMPRAS, ABONOS, DEVOLS, SDOFIN, CIA, MAYORIS, BONIF, ' +
        'VENCANT, '
      '   VENCREC, PORVENC, COBINTERNA, CARTERA)'
      'values'
      
        '  (:FECHA, :COMPRAS, :ABONOS, :DEVOLS, :SDOFIN, :CIA, :MAYORIS, ' +
        ':BONIF, '
      '   :VENCANT, :VENCREC, :PORVENC, :COBINTERNA, :CARTERA)')
    DeleteSQL.Strings = (
      'delete from edomay'
      'where'
      '  FECHA = :OLD_FECHA and'
      '  CIA = :OLD_CIA and'
      '  MAYORIS = :OLD_MAYORIS')
    Left = 360
    Top = 176
  end
  object qry_cargos: TQuery
    DatabaseName = 'manvehi'
    SQL.Strings = (
      
        'select a.mayoris, a.docto, a.pagare, a.fecha, a.tipago, a.concep' +
        ', a.importe, a.vence'
      'from movmay2 a'
      'where a.mayoris between  :PRMAYO and :ULMAYO'
      'and a.fecha between :FECINI and :FECFIN'
      'and a.coa='#39'C'#39' and a.cia = :CIA'
      'order by a.mayoris, a.docto, a.pagare,'
      'a.fecha, a.tipago, a.concep'
      ''
      ''
      ' ')
    Left = 424
    Top = 175
    ParamData = <
      item
        DataType = ftUnknown
        Name = 'PRMAYO'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'ULMAYO'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'FECINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'FECFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
end
